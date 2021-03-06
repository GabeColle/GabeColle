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
	 * 更新処理をする
	 */
	void update();
	/**
	 * 拍が変わった瞬間かどうかを返す
	 * @param 拍数(2 or 4)
	 * @return 拍が変わったかどうか
	 */
	bool getBeatRising(const int beat);
};

