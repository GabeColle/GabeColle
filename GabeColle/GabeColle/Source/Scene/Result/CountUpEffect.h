#pragma once

#include<Siv3D.hpp>

class CountUpEffect{
private:
	// カウントアップする変数
	int countedVariable_m;
	// カウンター
	int counter_m;
	// カウント終了までのフレーム数
	int frame_m;
	// カウンターの上がり幅
	int countRange_m;
	// 描画用
	const Font font;
	// 描画位置
	Vec2 position_m;
public:
	CountUpEffect(int countedVariable, int frame,Vec2 position);
	void countUp();
	void draw()const;
};