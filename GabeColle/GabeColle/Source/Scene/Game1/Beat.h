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
	 * XVˆ—‚ğ‚·‚é
	 */
	void update();
	/**
	 * ”‚ª•Ï‚í‚Á‚½uŠÔ‚©‚Ç‚¤‚©‚ğ•Ô‚·
	 * @return ”‚ª•Ï‚í‚Á‚½‚©‚Ç‚¤‚©
	 */
	bool getBeatRising();
};

