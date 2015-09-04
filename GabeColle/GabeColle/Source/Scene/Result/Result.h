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
	const String resultSentence = L"Time\nSegmentation Fault\n���������v���Z�X\n�������_";
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
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};