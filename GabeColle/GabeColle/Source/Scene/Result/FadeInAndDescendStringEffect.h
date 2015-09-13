#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class FadeInAndDescendStringEffect : public NodeEffect{
private:
	// 降臨させる文字
	String descendedString_m;
	// 現在の位置
	Vec2 currentPosition_m;
	// 不透明度
	int currentTransparency_m;
	// y方向の上げ幅
	int increaseYRange_m;
	// 不透明度の上げ幅
	int increaseTransparencyRange_m;
	// 描画用フォント
	Font drawingString_m;
public:
	FadeInAndDescendStringEffect(String str, int frame, int delayFrame, Vec2 position);
	void update();
	void draw()const;
};