#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class ExpandCircleEffect : public NodeEffect{
private:
	// Šg‘åƒGƒtƒFƒNƒg‚ğ‚©‚¯‚é‰~
	Circle expandedCircle_m;
	// ‰~‚ÌF
	Color color_m;
	// Œ³X‚Ì‰~‚Ì‘å‚«‚³‚©‚çŠg‘å—¦‚ğ‹tZ
	double magnificationRate_m;
	// Œ»İ‚ÌŠg‘å—¦
	double currentMagnificationRate_m;
	// Šg‘å—¦‚Ìã‚°•
	double increaseRange_m;
public:
	ExpandCircleEffect(Circle c, int frame, int delayFrame, Color color);
	void update();
	void draw()const;
};