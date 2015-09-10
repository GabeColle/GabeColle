#include"Start.h"
#include<thread>

using namespace clickable;

Start::Start()
	:titleFont_m(Font(120)), sakuras_m(50)
{}

// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
void Start::init()
{
	Graphics::SetBackground(Palette::Whitesmoke);

	logo_m = Texture(L"Asset/Image/GabeColle.png");
	back_m = Texture(L"Asset/Image/�܂�C���̐�.png");
	title_m = L"�K�x����";
	initButtons();
}

// ���t���[�� updateAndDraw() �ŌĂ΂��
void Start::update()
{
	buttons_m.at(L"Start")->update();
	buttons_m.at(L"Quit")->update();
	buttons_m.at(L"Twitter")->update();

	if (buttons_m.at(L"Quit")->isClicked()) {
		System::Exit();
	}
	if (buttons_m.at(L"Twitter")->isClicked()) {
		twitter_m = std::thread(
			Twitter::OpenTweetWindow, L"�K�x������v���C��\nhttp://jumpaku.hatenablog.com/entry/2015/09/04/001226");
		twitter_m.detach();
	}
	if (buttons_m.at(L"Start")->isClicked()) {
		changeScene(L"JumpakuGame");
	}

	std::for_each(sakuras_m.begin(), sakuras_m.end(), [] (SakuraTexture &s)
	{
		s.update();
	});
}

// ���t���[�� update() �̎��ɌĂ΂��
void Start::draw() const
{
	back_m.draw();
	std::for_each(sakuras_m.begin(), sakuras_m.end(),
		[] (SakuraTexture const &s) { s.draw(); });
	logo_m.scale(0.4).drawAt(Window::Center().movedBy(0, -120));
	buttons_m.at(L"Start")->draw();
	buttons_m.at(L"Quit")->draw();
	buttons_m.at(L"Twitter")->draw();
}

void Start::initButtons()
{
	auto addButton = [this] (Point p, String name, String sound)
	{
		auto btn = std::make_shared<Button>(Rect(200, 48).setCenter(p), name, sound);
		btn->show();
		buttons_m.insert(std::make_pair(	name, btn));
	};
	addButton(Window::Center().movedBy(0, 150), L"Start", L"Asset/SoundEffect/Decision.mp3");
	addButton(Window::Center().movedBy(0, 220), L"Quit", L"Asset/SoundEffect/Decision.mp3");
	addButton(Window::Center().movedBy(0, 290), L"Twitter", L"Asset/SoundEffect/Decision.mp3");
}
