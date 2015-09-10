#pragma once

#include <Siv3D.hpp>


class Beat
{
private:
	SoundBeat soundBeat_m;
	int nowBeat_m;
	int prevBeat_m;
public:
	Beat();
public:
	/**
	 * �X�V����������
	 */
	void update();
	/**
	 * �����ς�����u�Ԃ��ǂ�����Ԃ�
	 * @return �����ς�������ǂ���
	 */
	bool getBeatRising();
};

