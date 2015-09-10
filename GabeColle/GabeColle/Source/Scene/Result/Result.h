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
#include "RankingWindow.h"
#include "Record.h"

class Result :
	public SceneManager<String, GameData>::Scene
{
private:
	const int fontSize;
	const double circleRadius;
	const Texture backGround;
	const Font resultText;
	const Font stageNameText;
	const Sound BGM;

	const Texture texture; // resultBG2 著者:/\lex
	const Texture texture2;

	Circle circle_stage_m = Circle(Window::Center(),circleRadius);
	Circle circle_time_m = Circle(circle_stage_m.center.x/2,circle_stage_m.center.y/2, circleRadius);
	Circle circle_error_m = Circle((Window::Width() + circle_stage_m.center.x) / 2, circle_time_m.y, circleRadius);
	Circle circle_process_m = Circle(circle_time_m.x, (Window::Height() + circle_stage_m.center.y) / 2, circleRadius);
	Circle circle_totalScore_m = Circle(circle_error_m.x, circle_process_m.y, circleRadius);
	ResultNode* results_m[4];
	StageNameNode* stageNode_m;

	int BGVelocity;
	int BG_X;
	int BG_X2;

public:
	Result();
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};