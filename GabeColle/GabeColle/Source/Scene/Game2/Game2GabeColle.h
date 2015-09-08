#pragma once

#include"../../GC/GarbageCollection.h"
#include"CircleObject.h"
#include"../../GC/Marking.h"

template<class DeriverdObject>
class Game2GabeColle 
{
public:
	typedef gc::GarbageCollection<DeriverdObject> super;

	/**
	*memory�ɑ΂��ăK�x�[�W�R���N�V���������s����
	*�j�������I�u�W�F�N�g����Ԃ�
	*@memory
	*/
	
	static int gc(gc::Memory<DeriverdObject> &memory)
	{
		int garbage = 0;
		auto map = super::mark(memory);
		for (super::Address_t address(1); address < memory.size(); ++address) {
			if (!map.isMarked(address)) {
				if (!memory.hasExpired(address)){
					garbage++;
					memory.free(address);
				}
			}
		}
		return garbage;
	}
};