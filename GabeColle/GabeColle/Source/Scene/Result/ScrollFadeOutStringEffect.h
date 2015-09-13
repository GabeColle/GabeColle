#pragma once

#include <Siv3d.hpp>
#include "NodeEffect.h"

class ScrollFadeOutStringEffect : NodeEffect{
private:
	int velocity;
	Font drawingText_m;
	String defaultString_m;
	String fadedInString_m;
	Vec2 fadedInPos_m;
	Circle node_m;
	int unClearRate;
	int unClearRateVelocity;


	void fadeout();
	void fadein();
public:
	ScrollFadeOutStringEffect(String fadeout,String fadein,Circle node,Font font,int frame,int delayFrame);
	void update();
	void draw()const;
};