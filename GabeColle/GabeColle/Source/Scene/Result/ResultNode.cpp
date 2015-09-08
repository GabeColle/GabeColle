#include "ResultNode.h"

ResultNode::ResultNode(int variable, String name, int delayFrame, Vec2 position) : test(0)
{
	variable_m = variable;
	name_m = name;
	delayFrame_m = delayFrame;
	position_m = position;
	Vec2 arrowEndPoint;
	double arrowAngle = Atan2(position_m.y - Window::Center().y, position_m.x - Window::Center().x);
	arrowEndPoint.x = position_m.x - circleRadius_m*Cos(arrowAngle);
	arrowEndPoint.y = position_m.y - circleRadius_m*Sin(arrowAngle);

	node_m = new Circle(position_m, circleRadius_m);
	
	effects[ARROW] = new ExtendArrowEffect(Line(Window::Center(), arrowEndPoint),30,delayFrame_m);
	effects[CIRCLE] = new ExpandCircleEffect(*node_m, 30, delayFrame_m+30, Palette::Darkred);
	effects[COUNTUP] = new CountUpEffect(variable_m,60,delayFrame_m+30*2,position_m);
	effects[NAME] = new FadeInAndDescendStringEffect(name, 30, delayFrame_m+30*2+60, Vec2(position_m.x, position_m.y + circleRadius_m));

	switchRanking = false;
	
}

void ResultNode::update()
{
	for (int i = 0; i < 4; ++i){
		effects[i]->update();
	}
}

void ResultNode::draw()const
{
	for (int i = 0; i < 4; ++i){
		effects[i]->draw();
	}
}

void ResultNode::pushButton()
{
	if (node_m->leftPressed){
		switchRanking = true;
	}
	if (switchRanking){
		test.draw();
	}
}