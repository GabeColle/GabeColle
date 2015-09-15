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
		* Root�������̈ʒu���擾����
		* @return Root�������̈ʒu
		*/
		Vec2 getRootPos();
		/**
		* �ʒu���X�g�̒����烉���_���ɒl���擾����
		* �������𐶐��������ɌĂяo��
		* @return �ʒu
		*/
		Vec2 getRandomPos();
		/**
		* �ʒu���X�g�ɒl��߂�
		* ��������free�������ɕK���Ă�
		* @param pos �߂��l
		*/
		void restoreRandomPos(Vec2 pos);
	private:
		void initPosList();
	};
}


