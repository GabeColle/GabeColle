#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"
#include "CountUpEffect.h"
#include "ExpandCircleEffect.h"
#include "ExtendArrowEffect.h"
#include "FadeInAndDescendStringEffect.h"
#include "RankingWindow.h"

class ResultNode{
private:
	static const int circleRadius_m = 100;

	enum{
		ARROW,
		CIRCLE,
		COUNTUP,
		NAME,
	};
	int variable_m;
	String name_m;
	int delayFrame_m;
	Vec2 position_m;
	Circle* node_m;
	NodeEffect* effects[4];
	RankingWindow test;
	bool switchRanking;
public:
	ResultNode(int variable, String name, int delayFrame,Vec2 position);
	void update();
	void draw()const;
	void pushButton();
};