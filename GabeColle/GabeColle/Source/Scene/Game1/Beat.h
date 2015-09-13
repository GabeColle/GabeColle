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
	 * XVˆ—‚ğ‚·‚é
	 */
	void update();
	/**
	 * ”‚ª•Ï‚í‚Á‚½uŠÔ‚©‚Ç‚¤‚©‚ğ•Ô‚·
	 * @param ””(2 or 4)
	 * @return ”‚ª•Ï‚í‚Á‚½‚©‚Ç‚¤‚©
	 */
	bool getBeatRising(const int beat);
};

