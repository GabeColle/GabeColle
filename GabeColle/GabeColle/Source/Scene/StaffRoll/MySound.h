#pragma once

#include <Siv3D.hpp>
#include <queue>

namespace staffroll{
	class MySound
	{
	private:
		const FilePath BGM_PATH;
		const String BGM_NAME;
		const Vec2 rootPos = { Window::Width() / 2.0, Window::Height() / 2.0 };
		String state_m;
		int frame_m;
		std::queue<String> states_m;
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

		void stopMusic();

		void update();
	private:
		void initialize();
	};
}



