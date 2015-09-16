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
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};