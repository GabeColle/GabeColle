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
	 * 更新処理をする
	 */
	void update();
	/**
	 * 拍が変わった瞬間かどうかを返す
	 * @return 拍が変わったかどうか
	 */
	bool getBeatRising();
};

