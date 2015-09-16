#pragma once

#include <Siv3D.hpp>


class Beat
{
private:
	const String BGM_NAME;
private:
	SoundBeat soundBeat_m;
	int nowBeat_m;
	int prevBeat_m;
public:
	Beat(const String BGMName, const int32 tempo);
public:
	Beat& operator=(const Beat& obj);
public:
	/**
	 * �X�V����������
	 */
	void update();
	/**
	 * �����ς�����u�Ԃ��ǂ�����Ԃ�
	 * @param ����(2 or 4)
	 * @return �����ς�������ǂ���
	 */
	bool getBeatRising(const int beat);
};

