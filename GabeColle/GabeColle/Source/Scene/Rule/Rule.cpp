#include "Rule.h"

String const Rule::bgm_m = L"Asset/BGM/魔空.ogg";

Rule::Rule()
	:button_m(Rect(200, 80).setCenter(Window::Center().moveBy(0, 300)), L"戻る", 300, L"Asset/SoundEffect/Decision.ogg")
{
	if (!SoundAsset::IsRegistered(bgm_m)){
		SoundAsset::Register(bgm_m, bgm_m);
	}
}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Rule::init()
{
	button_m.show();
	title = Font(70);
	subtitle = Font(40);
	text = Font(20);
	mainimage = Texture(L"Asset/Image/ruletext.png");
	game1_m = Texture(L"Asset/Image/ScreenShot_Game1.png");
	game2_m = Texture(L"Asset/Image/ScreenShot_Game2.png");
	game3_m = Texture(L"Asset/Image/Game3Scene.png");

	for (int i = 0; i < 40; i++){
		cir[i] = Cir(Random(0,Window::Width()),Random(0,Window::Height()), 30, (2 * (i+1))%5+1);
	}
	back = Circle(Window::Width() / 2, Window::Height() / 2-30, 40);
	font = Font(20);
	click = Font(10);

	SoundAsset(bgm_m).play();
}

// 毎フレーム updateAndDraw() で呼ばれる
void Rule::update()
{

	Graphics::SetBackground(HSV(System::FrameCount(),0.6,0.9));


	for (int i = 0; i < 40; i++){
		switch (i % 4){
		case 0:
			cir[i].rightmove();
			break;
		case 1:
			cir[i].leftmove();
			break;
		case 2:
			cir[i].sinmove();
			break;
		case 3:
			cir[i].sinmove2();
			break;
		default:
			break;
		}
		cir[i].update();
		if(cir[i].getE())click.drawCenter(L"click",{cir[i].getX(),cir[i].getY()},Palette::White);
	}
	backbutton = back.mouseOver;
	if (back.leftClicked){ changeScene(L"Start"); }
	button_m.update();
	
	if (button_m.isClicked()){
		SoundAsset(bgm_m).stop();
		changeScene(L"Start");
	}
}

// 毎フレーム update() の次に呼ばれる
void Rule::draw() const
{
	int t = System::FrameCount()*3;
	game1_m.draw(t % (1280 * 3) - 1280, 0, Alpha(50));
	game2_m.draw((t+1280) % (1280 * 3) - 1280, 0, Alpha(50));
	game3_m.draw((t + 2560) % (1280 * 3) - 1280, 0, Alpha(50));

	for (int i = 0; i < 40; i++)
	{
		cir[i].draw();
	}

	RoundRect(Rect(700, 700).setCenter(Window::Center()).movedBy(0, 0), 20).draw(Color(Palette::White, 180)).drawFrame(0.0, 3.0, Palette::Black);

	mainimage.drawAt(Window::Width() / 2, Window::Height() * 3 / 4 - 90);

	title(L"ルール！").drawCenter({ Window::Width() / 2, title.size }, Color(255, 0, 0));
	text(L"これはガベージコレクションをするゲームです").drawCenter({ Window::Width() / 2, (title.size + text.size) * 2 }, Color(0, 0, 0));
	subtitle(L"やり方").drawCenter({ Window::Width() / 2, (title.size + text.size + subtitle.size) * 2 }, Color(0, 0, 0));

	button_m.draw();
	clickable::Button::drawEffect();
	Cir::drawEffect();
}