#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"
#include"CountUpEffect.h"
#include"ExpandCircleEffect.h"
#include"ExtendArrowEffect.h"
#include"FeedInAndDescendStringEffect.h"

class Result :
	public SceneManager<String, GameData>::Scene
{
private:
	const int fontSize;
	const double circleRadius;
	const Texture backGround;
	const Font resultText;
	const Font stageNameText;
	const String resultSentence = L"Time\nSegmentation Fault\n処理したプロセス\n総合得点";
	Circle circle_stage_m = Circle(Window::Center(),circleRadius);
	Circle circle_time_m = Circle(circle_stage_m.center.x/2,circle_stage_m.center.y/2, circleRadius);
	Circle circle_error_m = Circle((Window::Width() + circle_stage_m.center.x) / 2, circle_time_m.y, circleRadius);
	Circle circle_process_m = Circle(circle_time_m.x, (Window::Height() + circle_stage_m.center.y) / 2, circleRadius);
	Circle circle_totalScore_m = Circle(circle_error_m.x, circle_process_m.y, circleRadius);
	//CountUpEffect* countedVariable_time;
	//CountUpEffect* countedVariable_error;
	//CountUpEffect* countedVariable_process;
	//CountUpEffect* countedVariable_totalScore;
	CountUpEffect* countups[4];
	ExpandCircleEffect* circles[5];
	ExtendArrowEffect* arrows[4];
	FeedInAndDescendStringEffect* texts[4];

public:
	Result();
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};