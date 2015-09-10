#include "ScrollFadeOutStringEffect.h"

ScrollFadeOutStringEffect::ScrollFadeOutStringEffect(String defaultString, String fadein, Circle node, Font font, int frame, int delayFrame) : NodeEffect(frame,delayFrame,node.center)
{
	unClearRate = 255;
	node_m = node;
	defaultString_m = defaultString;
	fadedInString_m = fadein;
	fadedInPos_m.x= node.center.x;
	fadedInPos_m.y = node.center.y + 100;
	drawingText_m = font;

	velocity = 100 / frame_m;
	unClearRateVelocity = 255 / frame_m;
}

void ScrollFadeOutStringEffect::update()
{
	if (delayFrame_m == 0){
		if (node_m.mouseOver){
			fadeout();
		}
		else{
			fadein();
		}
	}
	else{
		delayFrame_m--;
	}
	
}

void ScrollFadeOutStringEffect::fadeout()
{
	if (unClearRate > 0){
		position_m.y -= velocity;
		fadedInPos_m.y -= velocity;
		unClearRate -= unClearRateVelocity;
	}
	if(unClearRate <= 0){
		unClearRate = 0;
	}
}

void ScrollFadeOutStringEffect::fadein()
{
	if (unClearRate < 255){
		position_m.y += velocity;
		fadedInPos_m.y += velocity;
		unClearRate += unClearRateVelocity;
	}
	if (unClearRate >= 255){
		unClearRate = 255;
	}
}

void ScrollFadeOutStringEffect::draw()const
{
	drawingText_m(defaultString_m).drawCenter(position_m, Color(Palette::Bisque, unClearRate));
	drawingText_m(fadedInString_m).drawCenter(fadedInPos_m, Color(Palette::Cyan, 255 - unClearRate));
}