#include "ScrollFadeOutStringEffect.h"

ScrollFadeOutStringEffect::ScrollFadeOutStringEffect(String defaultString,String fadein, Circle node,Font font)
{
	unClearRate = 255;
	node_m = node;
	defaultString_m = defaultString;
	fadedInString_m = fadein;
	defaultPos_m = node.center;
	fadedInPos_m.x= node.center.x;
	fadedInPos_m.y = node.center.y + 100;
	drawingText_m = font;
}

void ScrollFadeOutStringEffect::update()
{
	if (node_m.mouseOver){
		fadeout();
	}
	else{
		fadein();
	}
}

void ScrollFadeOutStringEffect::fadeout()
{
	if (unClearRate > 0){
		defaultPos_m.y -= 4;
		fadedInPos_m.y -= 4;
		unClearRate -= 10;
	}
	if(unClearRate <= 0){
		unClearRate = 0;
	}
}

void ScrollFadeOutStringEffect::fadein()
{
	if (unClearRate < 255){
		defaultPos_m.y += 4;
		fadedInPos_m.y += 4;
		unClearRate += 10;
	}
	if (unClearRate >= 255){
		unClearRate = 255;
	}
}

void ScrollFadeOutStringEffect::draw()const
{
	drawingText_m(defaultString_m).drawCenter(defaultPos_m, Color(Palette::Bisque, unClearRate));
	drawingText_m(fadedInString_m).drawCenter(fadedInPos_m, Color(Palette::Cyan, 255 - unClearRate));
}