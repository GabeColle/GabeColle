#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include<map>
#include<thread>
#include"../GameData.h"
#include"../../Clickable/Button.h"

class Start :
	public SceneManager<String, GameData>::Scene
{
private:
	typedef std::shared_ptr<clickable::Button> Button_t;

	Texture logo_m;
	Font const titleFont_m;
	String title_m;
	std::map<String, Button_t> buttons_m;
	std::map<String, GUI> guis_m;

	std::thread twitter_m;

	void initButtons();
public:
	Start();
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};

