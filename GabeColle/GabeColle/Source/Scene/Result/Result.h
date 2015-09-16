#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>

#include "../GameData.h"
#include "Effect/CountUpEffect.h"
#include "Effect/ExpandCircleEffect.h"
#include "Effect/ExtendArrowEffect.h"
#include "Effect/FadeInAndDescendStringEffect.h"
#include "ResultNode.h"
#include "StageNameNode.h"
#include "RankingWindow.h"
#include "Record.h"
#include "BackGroundAnimation.h"
#include "TwitterButton.h"
#include "EndingButton.h"

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
	
	std::shared_ptr<ResultNode> results_m[4];
	std::shared_ptr<StageNameNode> stageNode_m;

	Circle returnButton_m;

	TwitterButton tweet_m;
	//EndingButton ending_m;

	

public:
	Result();
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};