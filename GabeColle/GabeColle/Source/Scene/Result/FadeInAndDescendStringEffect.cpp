#include"FadeInAndDescendStringEffect.h"

FadeInAndDescendStringEffect::FadeInAndDescendStringEffect(String str, int frame, int delayFrame, Vec2 position) : NodeEffect(frame,delayFrame,position),font_m(50)
{
	descendedString_m = str;
	position_m = position;
	currentPosition_m.x = position_m.x;
	currentPosition_m.y = position_m.y - 40;
	currentTransparency_m = 0;
	increaseYRange_m = 40 / frame_m;
	increaseTransparencyRange_m = 255 / frame_m;
}

void FadeInAndDescendStringEffect::update()
{
	if (delayFrame_m == 0){
		if (currentPosition_m.y < position_m.y){
			currentPosition_m.y += increaseYRange_m;
			
		}
		else{
			currentPosition_m.y = position_m.y;
		}
		if (currentTransparency_m < 255){
			currentTransparency_m += increaseTransparencyRange_m;
		}
		else{
			currentTransparency_m = 255;
		}
	}
	else{
		delayFrame_m--;
	}
	
}

void FadeInAndDescendStringEffect::draw()const
{
	font_m(descendedString_m).drawCenter(currentPosition_m, Color(0,0,0,currentTransparency_m));
}