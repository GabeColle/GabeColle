#include "ResultNode.h"

ResultNode::ResultNode(int id,int variable, String name, int delayFrame, Vec2 position)
{
	id_m = id;
	variable_m = variable;
	name_m = name;
	delayFrame_m = delayFrame;
	position_m = position;
	Vec2 arrowEndPoint;
	double arrowAngle = Atan2(position_m.y - Window::Center().y, position_m.x - Window::Center().x);
	arrowEndPoint.x = position_m.x - circleRadius_m*Cos(arrowAngle);
	arrowEndPoint.y = position_m.y - circleRadius_m*Sin(arrowAngle);

	node_m = std::make_shared<Circle>(Circle(position_m, circleRadius_m));
	
	effects[ARROW]	 =	std::make_shared<ExtendArrowEffect>(ExtendArrowEffect(Line(Window::Center(), arrowEndPoint), 30, delayFrame_m));
	effects[CIRCLE]	 =	std::make_shared<ExpandCircleEffect>(ExpandCircleEffect(*node_m, 30, delayFrame_m + 30, Palette::Darkred));
	effects[COUNTUP] =	std::make_shared<CountUpEffect>(CountUpEffect(variable,60,delayFrame_m+30*2,position_m));
	effects[NAME]	 =	std::make_shared<FadeInAndDescendStringEffect>(FadeInAndDescendStringEffect(name, 30, delayFrame_m+30*2+60, Vec2(position_m.x, position_m.y + circleRadius_m)));

	ranking_m = std::make_shared<RankingWindow>(RankingWindow(id_m,variable_m));

	switchRanking_m = false;
	
}

void ResultNode::update()
{
	for (int i = 0; i < 4; ++i){
		effects[i]->update();
		pushButton();
	}
}

void ResultNode::draw()const
{
	for (int i = 0; i < 4; ++i){
		effects[i]->draw();
	}
	if (switchRanking_m){
		ranking_m->draw();
	}
}

void ResultNode::pushButton()
{
	if (node_m->leftPressed){
		switchRanking_m = true;
	}
	if (ranking_m->pushButton()){
		switchRanking_m = false;
	}
}