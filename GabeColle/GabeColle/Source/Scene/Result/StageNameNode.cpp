#include "StageNameNode.h"

StageNameNode::StageNameNode(String name, int delayFrame, Vec2 position) : font_m(100, Typeface::Bold, FontStyle::Italic)
{
	stageName_m = name;
	delayFrame_m = delayFrame;
	position_m = position;

	node_m = new Circle(position_m, circleRadius_m);

	effect_m = new ExpandCircleEffect(*node_m,30,delayFrame_m,Palette::Aqua);

	turnOnNextStage = new ScrollFadeOutStringEffect(name,L"Return the title?",*node_m,font_m,30,100);
	
}

void StageNameNode::update()
{
	effect_m->update();
	turnOnNextStage->update();
}

void StageNameNode::draw()const
{
	effect_m->draw();
	turnOnNextStage->draw();
}