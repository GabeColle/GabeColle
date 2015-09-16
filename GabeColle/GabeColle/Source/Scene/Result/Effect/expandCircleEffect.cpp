#include"ExpandCircleEffect.h"

ExpandCircleEffect::ExpandCircleEffect(Circle c, int frame, int delayFrame, Color color) : NodeEffect(frame,delayFrame)
{
	expandedCircle_m = c;
	color_m = color;

	magnificationRate_m = expandedCircle_m.r / 5.0;
	currentMagnificationRate_m = 0.0;
	increaseRange_m = magnificationRate_m / frame_m;

	expandedCircle_m.r = 5.0;
}

void ExpandCircleEffect::update()
{
	if (delayFrame_m == 0){
		if (currentMagnificationRate_m < magnificationRate_m){
			currentMagnificationRate_m += increaseRange_m;
		}
		else{
			currentMagnificationRate_m = magnificationRate_m;
		}
	}
	else{
		delayFrame_m--;
	}
}

void ExpandCircleEffect::draw()const
{
	expandedCircle_m.scaled(currentMagnificationRate_m).draw(Color(color_m,128)).drawFrame(0.0, 3.0, Color(color_m.r/2,color_m.g/2,color_m.b/2));
}