#pragma once

#include<Siv3D.hpp>

class FadeInAndDescendStringEffect{
private:
	// 降臨させる文字
	String descendedString_m;
	// 何フレームかけて降臨させるか
	int frame_m;
	// 現在のフレーム数
	int currentFrame_m;
	// エフェクトを適用するフレーム数
	int delayFrame_m;
	// 現在の位置
	Vec2 currentPosition_m;
	// 描画位置
	Vec2 position_m;
	// 不透明度
	int currentTransparency_m;
	// y方向の上げ幅
	int increaseYRange_m;
	// 不透明度の上げ幅
	int increaseTransparencyRange_m;
	// 描画用フォント
	Font font_m;
public:
	FadeInAndDescendStringEffect(String str, int frame, int delayFrame, Vec2 position);
	void update();
	void draw();
};