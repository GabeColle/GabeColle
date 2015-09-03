#include "Start.h"

using namespace start;

Start::Start()
	:font_m(Font(30))
{

}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Start::init()
{
	Graphics::SetBackground(Palette::Whitesmoke);
	logo_m = Texture(L"Asset/Image/GabeColle.png");
	start_m = std::make_shared<Button>(
		Rect(Point(200,48)).setCenter(Window::Center()), L"Start", L"Asset/SoundEffect/Decision");
	/*quit_m = std::make_shared<Button>();
	rule_m = std::make_shared<Button>();
	description_m = std::make_shared<Button>();
	config_m = std::make_shared<Button>();
	twitter_m = std::make_shared<Button>();
	buttons_m.push_back(start_m);
	buttons_m.push_back(quit_m);
	buttons_m.push_back(rule_m);
	buttons_m.push_back(description_m);
	buttons_m.push_back(config_m);
	buttons_m.push_back(twitter_m);*/
}

// 毎フレーム updateAndDraw() で呼ばれる
void Start::update()
{
	start_m->update();
}

// 毎フレーム update() の次に呼ばれる
void Start::draw() const
{
	logo_m.scale(0.4).drawAt(Window::Width() - 250, 250);
	start_m->draw();
	font_m(ToString(start_m->isClicked())).draw(100.0,0.0,Palette::Black);
}