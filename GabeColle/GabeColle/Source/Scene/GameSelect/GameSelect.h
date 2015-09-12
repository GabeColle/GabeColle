#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

#include"Tag.h"
#include"Effect.h"
#include"../../Clickable/Button.h"
#include"../game2/TextField.h"

class GameSelect :
	public SceneManager<String, GameData>::Scene
{
protected:
	std::vector<gameselect::Tag> tag_m;
	std::vector<clickable::Button>buttons_m;
	Effect lingEffect_m;
	Effect lineEffect_m;
	Effect buttonEffect_m;
	Font font_m;

public:
	//コンストラクタ
	GameSelect()
		:font_m(50, L"Georgia", FontStyle::Italic)
	{};

	//デストラクタ
	~GameSelect(){};

	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;

protected:
	void background();
	void fft();
};
