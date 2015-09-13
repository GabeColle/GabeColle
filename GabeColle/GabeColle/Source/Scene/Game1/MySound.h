#pragma once

#include <Siv3D.hpp>


class MySound
{
private:
	const FilePath BGM_PATH;
	const String BGM_NAME;
public:
	MySound(const FilePath BGMPath, const String BGMName);
public:
	MySound& operator=(const MySound& obj);
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

