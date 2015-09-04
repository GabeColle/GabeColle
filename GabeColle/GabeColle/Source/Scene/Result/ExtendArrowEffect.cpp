#include"ExtendArrowEffect.h"

ExtendArrowEffect::ExtendArrowEffect(Line line, int frame,int delayFrame)
{
	originalPoint_m = line.begin;
	arrivalPoint_m = line.end;
	currentPoint_m = line.begin;
	frame_m = frame;
	currentFrame_m = 0;
	delayFrame_m = delayFrame;
	extendVelocity_m.x = (arrivalPoint_m.x - originalPoint_m.x) / frame_m;
	extendVelocity_m.y = (arrivalPoint_m.y - originalPoint_m.y) / frame_m;

}

void ExtendArrowEffect::update()
{
	if (delayFrame_m == 0){
		if (frame_m != currentFrame_m){
			currentPoint_m += extendVelocity_m;
			currentFrame_m++;
		}
		draw();
	}
	else{
		delayFrame_m--;
	}
	
}

void ExtendArrowEffect::draw()
{
	Line(originalPoint_m,currentPoint_m).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
}