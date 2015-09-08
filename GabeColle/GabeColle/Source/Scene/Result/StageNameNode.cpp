#include "StageNameNode.h"

StageNameNode::StageNameNode(String name, int delayFrame, Vec2 position) : font_m(100, Typeface::Bold, FontStyle::Italic)
{
	stageName_m = name;
	delayFrame_m = delayFrame;
	position_m = position;

	node_m = new Circle(position_m, circleRadius_m);

	effect_m = new ExpandCircleEffect(*node_m,30,delayFrame_m,Palette::Aqua);

}

void StageNameNode::update()
{
	effect_m->update();
}

void StageNameNode::draw()const
{
	effect_m->draw();
	font_m(stageName_m).drawCenter(position_m, Palette::Azure);
}