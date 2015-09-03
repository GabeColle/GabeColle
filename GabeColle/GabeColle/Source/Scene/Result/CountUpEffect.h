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
public:
	CountUpEffect(int countedVariable, int frame);
	void countUp();
	void draw(int x,int y)const;
};