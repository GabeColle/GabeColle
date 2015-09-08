#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"
#include"CountUpEffect.h"
#include"ExpandCircleEffect.h"
#include"ExtendArrowEffect.h"
#include"FadeInAndDescendStringEffect.h"
#include "ResultNode.h"
#include "StageNameNode.h"

class Result :
	public SceneManager<String, GameData>::Scene
{
private:
	const int fontSize;
	const double circleRadius;
	const Texture backGround;
	const Font resultText;
	const Font stageNameText;
	Circle circle_stage_m = Circle(Window::Center(),circleRadius);
	Circle circle_time_m = Circle(circle_stage_m.center.x/2,circle_stage_m.center.y/2, circleRadius);
	Circle circle_error_m = Circle((Window::Width() + circle_stage_m.center.x) / 2, circle_time_m.y, circleRadius);
	Circle circle_process_m = Circle(circle_time_m.x, (Window::Height() + circle_stage_m.center.y) / 2, circleRadius);
	Circle circle_totalScore_m = Circle(circle_error_m.x, circle_process_m.y, circleRadius);
	ResultNode* results_m[4];
	StageNameNode* stageNode_m;

public:
	Result();
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};