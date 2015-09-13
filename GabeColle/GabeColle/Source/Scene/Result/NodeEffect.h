#pragma once

#include <Siv3D.hpp>

class NodeEffect{
protected:
	int frame_m;
	int delayFrame_m;
	Vec2 position_m;
public:
	NodeEffect(int frame, int delayFrame, Vec2 position);
	NodeEffect(int frame, int delayFrame);
	virtual void update() = 0;
	virtual void draw()const = 0;
};