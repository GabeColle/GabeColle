#pragma once

#include<Siv3D.hpp>
#include"CountUpEffect.h"
#include"ExpandCircleEffect.h"
#include"ExtendArrowEffect.h"
#include"FadeInAndDescendStringEffect.h"

class PluralAnimation{
private:
	int frame_m;
	int delayFrame_m;

	CountUpEffect* countups[4];
	ExpandCircleEffect* circles[5];
	ExtendArrowEffect* arrows[4];
	FadeInAndDescendStringEffect* texts[4];
public:
	PluralAnimation(int frame, int delayFrame);
	void init();
	void pluralPlay();
};