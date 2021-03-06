#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "MemoryWrapper.h"
#include "StaffRollContent.h"
#include "MySound.h"

#include"../GameData.h"

class StaffRoll
	: public SceneManager<String, GameData>::Scene
{
private:
	int changeFrame_m;
	int contentNumber_m;
	Array<std::shared_ptr<StaffRollContent>> contents_m;
	staffroll::MySound sound_m;
public:
	StaffRoll();
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};
