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
#include "BackGroundAnimation.h"

class Result :
	public SceneManager<String, GameData>::Scene
{
private:
	const int fontSize;
	const double circleRadius;
	const Texture backGround;
	const Font resultText;
	const Font stageNameText;
	
	BackGroundAnimation bg;
	
	ResultNode* results_m[4];
	StageNameNode* stageNode_m;

	

public:
	Result();
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};