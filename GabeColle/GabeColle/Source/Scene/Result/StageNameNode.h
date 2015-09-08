#pragma once

#include <Siv3D.hpp>
#include "ExpandCircleEffect.h"

class StageNameNode{
private:
	static const int circleRadius_m = 100;
	String stageName_m;
	int delayFrame_m;
	Vec2 position_m;
	Circle* node_m;

	ExpandCircleEffect* effect_m;

	const Font font_m;

public:
	StageNameNode(String name, int delayFrame, Vec2 position);
	void update();
	void draw()const;
};