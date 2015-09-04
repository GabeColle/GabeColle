#include"PluralAnimation.h"

PluralAnimation::PluralAnimation(CountUpEffect* countup, ExpandCircleEffect* expand, ExtendArrowEffect* extend, FadeInAndDescendStringEffect* feedin, int delayFrame)
{
	countup_m = countup;
	expand_m = expand;
	extend_m = extend;
	feedin_m = feedin;
	int delayFrame_m = delayFrame;
}