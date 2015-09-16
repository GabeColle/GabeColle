#include "ScrollFadeOutStringEffect.h"

ScrollFadeOutStringEffect::ScrollFadeOutStringEffect(String defaultString, String fadein, Circle node, Font font, int frame, int delayFrame) : NodeEffect(frame,delayFrame,node.center)
{
	unClearRate_m = 255;
	node_m = node;
	defaultString_m = defaultString;
	fadedInString_m = fadein;
	fadedInPos_m.x= node.center.x;
	fadedInPos_m.y = node.center.y + 100;
	drawingText_m = font;

	velocity_m = 100 / frame_m;
	unClearRateVelocity_m = 255 / frame_m;
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
	if (unClearRate_m > 0){
		position_m.y -= velocity_m;
		fadedInPos_m.y -= velocity_m;
		unClearRate_m -= unClearRateVelocity_m;
	}
	if(unClearRate_m <= 0){
		unClearRate_m = 0;
	}
}

void ScrollFadeOutStringEffect::fadein()
{
	if (unClearRate_m < 255){
		position_m.y += velocity_m;
		fadedInPos_m.y += velocity_m;
		unClearRate_m += unClearRateVelocity_m;
	}
	if (unClearRate_m >= 255){
		unClearRate_m = 255;
	}
}

void ScrollFadeOutStringEffect::draw()const
{
	drawingText_m(defaultString_m).drawCenter(position_m, Color(Palette::Bisque, unClearRate_m));
	drawingText_m(fadedInString_m).drawCenter(fadedInPos_m, Color(Palette::Cyan, 255 - unClearRate_m));
}