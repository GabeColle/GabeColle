#include "StageNameNode.h"

StageNameNode::StageNameNode(String name, int delayFrame, Vec2 position) : font_m(100, Typeface::Bold, FontStyle::Italic)
{
	stageName_m = name;
	delayFrame_m = delayFrame;
	position_m = position;

	node_m = std::make_shared<Circle>(Circle(position_m, circleRadius_m));

	effect_m = std::make_shared<ExpandCircleEffect>(ExpandCircleEffect(*node_m,30,delayFrame_m,Palette::Aqua));
	
	turnOnNextStage_m = std::make_shared<ScrollFadeOutStringEffect>(ScrollFadeOutStringEffect(name,L"Return the title?",*node_m,font_m,30,100));
	
}

void StageNameNode::update()
{
	effect_m->update();
	turnOnNextStage_m->update();
}

void StageNameNode::draw()const
{
	effect_m->draw();
	turnOnNextStage_m->draw();
}