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
	 * 音楽の再生を開始する
	 */
	void startMusic();
	/**
	 * スペクトラムを表示する
	 */
	void drawSpectrum() const;
	/**
	 * 音楽の再生が終了したかを返す
	 * @return 終了フラグ
	 */
	bool isEnded();
private:
	void initialize();
};

