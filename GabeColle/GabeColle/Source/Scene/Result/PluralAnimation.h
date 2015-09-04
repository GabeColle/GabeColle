#pragma once

#include<Siv3D.hpp>
#include"CountUpEffect.h"
#include"ExpandCircleEffect.h"
#include"ExtendArrowEffect.h"
#include"FadeInAndDescendStringEffect.h"

class PluralAnimation{
private:
	CountUpEffect* countup_m;
	ExpandCircleEffect* expand_m;
	ExtendArrowEffect* extend_m;
	FadeInAndDescendStringEffect* feedin_m;

	int delayFrame_m;
public:
	PluralAnimation(CountUpEffect*, ExpandCircleEffect*, ExtendArrowEffect*, FadeInAndDescendStringEffect*, int delayFrame);
	void pluralPlay();
};