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
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};