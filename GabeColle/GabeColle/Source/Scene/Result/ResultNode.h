#pragma once

#include <Siv3D.hpp>
#include "Effect/NodeEffect.h"
#include "Effect/CountUpEffect.h"
#include "Effect/ExpandCircleEffect.h"
#include "Effect/ExtendArrowEffect.h"
#include "Effect/FadeInAndDescendStringEffect.h"
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
	std::shared_ptr<Circle> node_m;
	std::shared_ptr<NodeEffect> effects[4];
	std::shared_ptr<RankingWindow> ranking_m;
	bool switchRanking_m;

	void pushButton();
public:
	ResultNode(int id, int variable, String name, int delayFrame,Vec2 position);
	void update();
	void draw()const;
};