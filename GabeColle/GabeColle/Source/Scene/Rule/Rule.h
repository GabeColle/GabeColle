#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include"../GameData.h"
#include "Cir.h"
#include"../../Clickable/Button.h"


class Rule :
	public SceneManager<String, GameData>::Scene
{
private:
	Font title;
	Font subtitle;
	Font text;
	Rect titleRect;
	Cir cir[40];
	Circle back;
	Texture mainimage;

	Texture game1_m;
	Texture game2_m;
	Texture game3_m;

	Font click;
	Font font;
	bool backbutton;
	clickable::Button button_m;

public:
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;

	Rule();
};
