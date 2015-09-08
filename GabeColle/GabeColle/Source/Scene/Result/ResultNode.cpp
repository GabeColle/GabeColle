#include "ResultNode.h"

ResultNode::ResultNode(int variable, String name, int delayFrame, Vec2 position)
{
	variable_m = variable;
	name_m = name;
	delayFrame_m = delayFrame;
	position_m = position;

	node_m = new Circle(position_m, circleRadius_m);
	
	effects[ARROW] = new ExtendArrowEffect(Line(Window::Center(), position_m),30,delayFrame_m);
	effects[CIRCLE] = new ExpandCircleEffect(*node_m, 30, delayFrame_m+30, Palette::Darkred);
	effects[COUNTUP] = new CountUpEffect(variable_m,60,delayFrame_m+30*2,position_m);
	effects[NAME] = new FadeInAndDescendStringEffect(name, 30, delayFrame_m+30*2+60, Vec2(position_m.x, position_m.y + circleRadius_m));
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