#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class ExpandCircleEffect : public NodeEffect{
private:
	// 拡大エフェクトをかける円
	Circle expandedCircle_m;
	// 円の色
	Color color_m;
	// 元々の円の大きさから拡大率を逆算
	double magnificationRate_m;
	// 現在の拡大率
	double currentMagnificationRate_m;
	// 拡大率の上げ幅
	double increaseRange_m;
public:
	ExpandCircleEffect(Circle c, int frame, int delayFrame, Color color);
	void update();
	void draw()const;
};