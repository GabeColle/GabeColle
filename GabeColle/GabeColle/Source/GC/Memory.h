#pragma once

#include <Siv3D.hpp>
#include"GarbageCollection.h"
#include"Object.h"
#include"Error.h"

namespace gc {

template<class DerivedObject>
class GarbageCollection;

/**
*仮想的なメモリ
*/
template<class DerivedObject>
class Memory
{
public:
	/**番地の型(int)*/
	typedef int Address_t;
private:
	std::vector<DerivedObject> memory_m;
	Relation relation_m;
	Error mutable error_m;
private:
	void check(Address_t address)const
	{
		if (hasExpired(address)) {
			++error_m.segmentationFault_m;
		}
		else if (address == 0) {
			++error_m.nullptrAccess_m;
		}
		else if (address <= -1 || size() <= address) {
			++error_m.addressOutOfBounds_m;
		}
	}
public:
	/**
	*コンストラクタ
	*@param size 生成できる最大のオブジェクト数
	*/
	Memory(int size) : relation_m(size), memory_m(std::vector<DerivedObject>(size))
	{
		memory_m[0].construct();
	}

	/**
	*オブジェクトを1つ生成する
	*@return 生成したオブジェクトの番地
	*/
	Address_t alloc()
	{
		for (Address_t address(1); address < size(); ++address) {
			if (!memory_m[address].exists()) {
				memory_m[address].construct();
				return address;
			}
		}
		++error_m.outOfMemory_m;
		return 0;
	}

	/**
	*addressが指定する番地のオブジェクトを破棄する
	@param address 破棄するオブジェクトの番地
	*/
	void free(Address_t address)
	{
		Marking const &&map = mark();
		if (address != 0) {
			if (map.isMarked(address)) {
				++error_m.segmentationFault_m;
			}
			for (Address_t to(0); to < size(); ++to) {
				unlink(address, to);
			}
			for (Address_t from(1); from < size(); ++from) {
				if (!map.isMarked(from)) {
					unlink(from, address);
				}
			}
			memory_m[address].destruct();
		}
	}

	/**
	*番地fromのオブジェクトと番地toのオブジェクトを繋ぐ
	*@param from
	*@param to
	*/
	void link(Address_t from, Address_t to)
	{
		if (!hasExpired(from) && !hasExpired(to)) {
			relation_m.link(from, to);
		}
	}

	/**
	*番地fromのオブジェクトと番地toのオブジェクトを切り離す
	*@param from
	*@param to
	*/
	void unlink(Address_t from, int to)
	{
		relation_m.unlink(from, to);
	}

	/**
	*オブジェクトがルートから参照を辿れるかどうかを調べる
	*@return 調べた結果
	*@see Marking
	*/
	Marking mark()const
	{
		return GarbageCollection<DerivedObject>::mark(*this);
	}

	/**
	*ルートから辿れないオブジェクトを破棄する
	*/
	void gc()
	{
		GarbageCollection<DerivedObject>::gc(*this);
	}

	/**
	*addressのオブジェクトが破棄されているか調べる
	*@return 破棄されている場合真
	*/
	bool hasExpired(Address_t address)const
	{
		return !memory_m[address].exists();
	}

	/**
	*addressのオブジェクトを参照する
	*@param address
	*@return オブジェクトの参照
	*/
	DerivedObject &access(Address_t address)
	{
		check(address);
		assert(0 < address && address < size());
		return memory_m[address];
	}

	/**
	*addressのオブジェクトを参照する
	*@param address
	*@return オブジェクトの参照
	*/
	DerivedObject const &access(Address_t address)const
	{
		check(address);
		assert(0 < address && address < size());
		return memory_m[address];
	}

	/**
	*@return 現在のオブジェクト同士のの関係
	*@see Relation
	*/
	Relation const &getRelation()const
	{
		return relation_m;
	}

	/**
	*@return 生成できる最大のオブジェクト数
	*/
	int size()const
	{
		return memory_m.size();
	}

	/**
	*@return 今までに発生したエラー
	*@see Error
	*/
	Error const &error()const
	{
		return error_m;
	}

	/**
	*@return ルートオブジェクトの参照
	*/
	DerivedObject &root()
	{
		return memory_m[0];
	}

	/**
	*@return ルートオブジェクトの参照
	*/
	DerivedObject const &root()const
	{
		return memory_m[0];
	}
	void error(Error const &e)const
	{
		error_m = e;
	}
};

}