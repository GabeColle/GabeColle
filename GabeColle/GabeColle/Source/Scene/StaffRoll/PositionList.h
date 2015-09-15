#pragma once

#include <Siv3D.hpp>
#include <list>

namespace staffroll{
	class PositionList
	{
	private:
		static const int MEMORY_RADIUS;
		static const int ROOT_RADIUS;
		static const int POSITION_NUM_X;
		static const int POSITION_NUM_Y;
		static const int POSITION_MARGIN_X;
		static const int POSITION_MARGIN_Y;
	private:
		Array<Vec2> posList_m;
		Vec2 rootPos_m;
	public:
		PositionList();
		~PositionList() = default;
	public:
		/**
		* Rootメモリの位置を取得する
		* @return Rootメモリの位置
		*/
		Vec2 getRootPos();
		/**
		* 位置リストの中からランダムに値を取得する
		* メモリを生成した時に呼び出す
		* @return 位置
		*/
		Vec2 getRandomPos();
		/**
		* 位置リストに値を戻す
		* メモリをfreeした時に必ず呼ぶ
		* @param pos 戻す値
		*/
		void restoreRandomPos(Vec2 pos);
	private:
		void initPosList();
	};
}


