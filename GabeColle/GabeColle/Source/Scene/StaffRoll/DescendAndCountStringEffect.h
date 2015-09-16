#pragma once

#include <Siv3D.hpp>
#include "../Result/Effect/NodeEffect.h"

class DescendAndCountStringEffect : public NodeEffect{
private:
	// 本当の文字
	String realString_m;
	// 降臨させる文字
	String descendedString_m;
	// スタート位置
	int startPos_m;
	// 不透明度
	int currentTransparency_m;
	// y方向の上げ幅
	int increaseYRange_m;
	// 不透明度の上げ幅
	int increaseTransparencyRange_m;
	// 描画用フォント
	Font drawingString_m;
	int stringCountFrame_m;
public:
	DescendAndCountStringEffect(String str, int frame, int delayFrame);
	void update();
	void draw()const;
	void draw(Vec2 realPosition)const;
	void setPosition(Vec2 position);
	String inverseCalculationString(String str,int frame);
	String incrementString(String str);
};
