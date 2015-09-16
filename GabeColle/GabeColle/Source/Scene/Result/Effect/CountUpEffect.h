#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class CountUpEffect : public NodeEffect{
private:
	// カウントアップする変数
	int countedVariable_m;
	// カウンター
	int counter_m;
	// カウンターの上がり幅
	int countRange_m;
	// 描画用
	Font drawingVariable_m;
public:
	CountUpEffect(int countedVariable, int frame, int delayFrame, Vec2 position);
	void update();
	void draw()const;
};