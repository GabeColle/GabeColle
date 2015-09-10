#pragma once

#include <Siv3D.hpp>


class MySound
{
private:
	static const FilePath BGM_PATH;
public:
	MySound();
public:
	/**
	 * ���y�̍Đ����J�n����
	 */
	void startMusic();
	/**
	 * �X�y�N�g������\������
	 */
	void drawSpectrum() const;
	/**
	 * ���y�̍Đ����I����������Ԃ�
	 * @return �I���t���O
	 */
	bool isEnded();
private:
	void initialize();
};

