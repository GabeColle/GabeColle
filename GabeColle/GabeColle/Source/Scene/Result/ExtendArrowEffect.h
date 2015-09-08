#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class ExtendArrowEffect : public NodeEffect{
private:
	// 出発点
	Vec2 originalPoint_m;
	// 到着点
	Vec2 arrivalPoint_m;
	// 現在のポイント
	Vec2 currentPoint_m;
	// 矢印が伸びる速度
	Vec2 extendVelocity_m;
public:
	ExtendArrowEffect(Line line, int frame_m,int delayFrame_m);
	void update();
	void draw()const;
};