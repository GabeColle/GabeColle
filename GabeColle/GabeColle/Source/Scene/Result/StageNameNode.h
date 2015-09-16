#pragma once

#include <Siv3D.hpp>
#include "Effect/ExpandCircleEffect.h"
#include "Effect/ScrollFadeOutStringEffect.h"

class StageNameNode{
private:
	static const int circleRadius_m = 100;
private:

	String stageName_m;
	
	Vec2 position_m;
	
	std::shared_ptr<Circle> node_m;
	std::shared_ptr<ExpandCircleEffect> effect_m;
	std::shared_ptr<ScrollFadeOutStringEffect> turnOnNextStage_m;

	Font font_m;

	int delayFrame_m;

public:
	StageNameNode(String name, int delayFrame, Vec2 position);
	void update();
	void draw()const;
};