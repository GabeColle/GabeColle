#include"ExpandCircleEffect.h"

ExpandCircleEffect::ExpandCircleEffect(Circle c, int frame, int delayFrame, Color color)
{
	expandedCircle_m = c;
	frame_m = frame;
	delayFrame_m = delayFrame;
	color_m = color;

	currentFrame_m = 0;
	magnificationRate_m = expandedCircle_m.r / 5.0;
	currentMagnificationRate_m = 0.0;
	increaseRange_m = magnificationRate_m / frame_m;

	expandedCircle_m.r = 5.0;
}

void ExpandCircleEffect::update()
{
	if (currentFrame_m > delayFrame_m){
		draw();
		currentMagnificationRate_m += increaseRange_m;
	}
	else{
		currentFrame_m++;
	}
}

void ExpandCircleEffect::draw()const
{
	if (currentMagnificationRate_m < magnificationRate_m){
		expandedCircle_m.scaled(currentMagnificationRate_m).draw(color_m).drawFrame(0.0, 3.0, color_m);
	}
	else{
		expandedCircle_m.scaled(magnificationRate_m).draw(color_m).drawFrame(0.0, 3.0, color_m);
	}
}