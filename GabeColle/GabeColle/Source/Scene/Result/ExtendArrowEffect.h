#pragma once

#include<Siv3D.hpp>

class ExtendArrowEffect{
private:
	// 出発点
	Vec2 originalPoint_m;
	// 到着点
	Vec2 arrivalPoint_m;
	// 現在のポイント
	Vec2 currentPoint_m;
	// 到着に要するフレーム数
	int frame_m;
	// 現在のフレーム数
	int currentFrame_m;
	// 矢印が伸びる速度
	Vec2 extendVelocity_m;
public:
	ExtendArrowEffect(Line line, int frame_m);
	void update();
	void draw();
};