#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"
#include "CountUpEffect.h"
#include "ExpandCircleEffect.h"
#include "ExtendArrowEffect.h"
#include "FadeInAndDescendStringEffect.h"
#include "RankingWindow.h"
#include "Record.h"


class ResultNode{
private:
	static const int circleRadius_m = 100;
	int id_m;
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
	RankingWindow* ranking;
	bool switchRanking;

	void pushButton();
public:
	ResultNode(int id, int variable, String name, int delayFrame,Vec2 position);
	void update();
	void draw()const;
};