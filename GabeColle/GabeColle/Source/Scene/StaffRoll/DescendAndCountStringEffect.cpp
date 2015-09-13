#include "DescendAndCountStringEffect.h"

DescendAndCountStringEffect::DescendAndCountStringEffect(String str, int frame, int delayFrame) : NodeEffect(frame,delayFrame)
{
	startPos = 40;
	descendedString_m = str;
	currentTransparency_m = 0;
	increaseYRange_m = 40 / frame_m;
	increaseTransparencyRange_m = 255 / frame_m;
}

void DescendAndCountStringEffect::update()
{
	if (delayFrame_m == 0){
		if (startPos > 0){
			startPos -= increaseYRange_m;
		}
		else{
			startPos = 0;
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

void DescendAndCountStringEffect::draw()const
{

}

void DescendAndCountStringEffect::draw(Vec2 realPosition)const
{
	Vec2 drawingPosition(realPosition.x, realPosition.y - startPos);
	drawingString_m(descendedString_m).drawCenter(drawingPosition, Color(0, 0, 0, currentTransparency_m));
}

void DescendAndCountStringEffect::setPosition(Vec2 position)
{
	position_m = position;
}

void DescendAndCountStringEffect::inverseCalculationString(String str,int frame)
{
	for (int i = 0; i < frame; ++i){
		str[i] = str[i] - frame;
	}
}