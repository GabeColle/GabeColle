#include"Start.h"
#include<thread>

using namespace clickable;

String const Start::bgm_m = L"Asset/BGM/StartBGM.mp3";

Start::Start()
	:titleFont_m(Font(120)), sakuras_m(50)
{
	if (!SoundAsset::IsRegistered(bgm_m)) {
		SoundAsset::Register(bgm_m, bgm_m);
	}
	SoundAsset(bgm_m).setLoop(true);
	SoundAsset(bgm_m).play();
}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Start::init()
{
	Graphics::SetBackground(Palette::Whitesmoke);

	logo_m = Texture(L"Asset/Image/GabeColle.png");
	back_m = Texture(L"Asset/Image/曇り気味の青空.png");
	rightGirl_m = Texture(L"Asset/Image/Imouto.png");
	leftGirl_m = Texture(L"Asset/Image/Heroine.png");
	rightBoy_m = Texture(L"Asset/Image/Okama.png");
	leftBoy_m = Texture(L"Asset/Image/Yamada.png");
	title_m = L"ガベこれ";
	initButtons();
}

// 毎フレーム updateAndDraw() で呼ばれる
void Start::update()
{
	buttons_m.at(L"Start")->update();
	buttons_m.at(L"Quit")->update();
	buttons_m.at(L"Rules")->update();

	if (buttons_m.at(L"Start")->isClicked()){
		SoundAsset(bgm_m).stop();
		changeScene(L"GameSelect");
	}
	if (buttons_m.at(L"Quit")->isClicked()) {
		System::Exit();
	}
	if (buttons_m.at(L"Rules")->isClicked()) {
		SoundAsset(bgm_m).stop();
		changeScene(L"Rules");
	}

	std::for_each(sakuras_m.begin(), sakuras_m.end(),
		[] (SakuraTexture &s){
			s.update();
		});
}

// 毎フレーム update() の次に呼ばれる
void Start::draw() const
{
	back_m.draw();
	std::for_each(sakuras_m.begin(), sakuras_m.end(),
		[] (SakuraTexture const &s) { s.draw(); });
	rightGirl_m.scale(0.9).drawAt(Window::Center().movedBy(550, 170));
	leftGirl_m.drawAt(Window::Center().movedBy(-500, 180));
	rightBoy_m.scale(0.9).drawAt(Window::Center().movedBy(350, -40));
	leftBoy_m.scale(0.9).drawAt(Window::Center().movedBy(-350, -40));

	logo_m.scale(0.4).drawAt(Window::Center().movedBy(0, -120));
	buttons_m.at(L"Start")->draw();
	buttons_m.at(L"Quit")->draw();
	buttons_m.at(L"Rules")->draw();
	Button::drawEffect();
}

void Start::initButtons()
{
	auto addButton = [this] (Point p, String name, String sound)
	{
		auto btn = std::make_shared<Button>(Rect(200, 48).setCenter(p), name, sound);
		btn->show();
		buttons_m.insert(std::make_pair(	name, btn));
	};
	addButton(Window::Center().movedBy(0, 150), L"Start", L"Asset/SoundEffect/NextScene.mp3");
	addButton(Window::Center().movedBy(0, 220), L"Quit", L"Asset/SoundEffect/Decision.mp3");
	addButton(Window::Center().movedBy(0, 290), L"Rules", L"Asset/SoundEffect/NextScene.mp3");
}
