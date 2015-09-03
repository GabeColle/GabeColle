#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"
#include"Button.h"

class Start :
	public SceneManager<String, GameData>::Scene
{
private:
	typedef std::shared_ptr<start::Button> Button_t;

	Texture logo_m;
	Button_t start_m;
	Button_t quit_m;
	Button_t rule_m;
	Button_t description_m;
	Button_t config_m;
	Button_t twitter_m;
	Font const font_m;
	std::list<Button_t> buttons_m;
public:
	Start();
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};

