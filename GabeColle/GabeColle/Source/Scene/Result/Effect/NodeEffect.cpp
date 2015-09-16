#include "NodeEffect.h"

NodeEffect::NodeEffect(int frame, int delayFrame, Vec2 position)
{
	frame_m = (frame == 0) ? 1 : frame;
	delayFrame_m = delayFrame;
	position_m = position;
}

NodeEffect::NodeEffect(int frame, int delayFrame)
{
	frame_m = (frame==0) ? 1 : frame;
	delayFrame_m = delayFrame;
	position_m = Vec2(0, 0);
}