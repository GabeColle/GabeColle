#include"PluralAnimation.h"

PluralAnimation::PluralAnimation(int frame, int delayFrame)
{
	frame_m = frame;
	delayFrame_m = delayFrame;
}

void PluralAnimation::init()
{

}

void PluralAnimation::pluralPlay()
{
	if (delayFrame_m == 0){
	}
	else{
		delayFrame_m--;
	}
	
}