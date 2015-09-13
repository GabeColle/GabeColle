#include "Rule.h"


Rule::Rule()
	:button_m(Rect(200, 80).setCenter(Window::Center().moveBy(0, 300)), L"戻る", 300, L"Asset/SoundEffect/Decision.ogg")
{}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Rule::init()
{
	button_m.show();
	title = Font(70);
	subtitle = Font(40);
	text = Font(20);
	mainimage = Texture(L"Asset/Image/ruletext.png");
	for (int i = 0; i < 40; i++){
		cir[i] = Cir(Random(0,Window::Width()),Random(0,Window::Height()), 30, (2 * (i+1))%5+1);
	}
	back = Circle(Window::Width() / 2, Window::Height() / 2-30, 40);
	font = Font(20);
	click = Font(10);
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
		cir[i].draw();
		if(cir[i].getE())click.drawCenter(L"click",{cir[i].getX(),cir[i].getY()},Palette::White);
	}
	backbutton = back.mouseOver;
	if (back.leftClicked)changeScene(L"Start");
	mainimage.drawAt(Window::Width() / 2, Window::Height() * 3 / 4 - 90);

	title(L"ルール！").drawCenter({ Window::Width() / 2, title.size }, Color(255, 0, 0));
	text(L"これはガベージコレクションをするゲームです").drawCenter({ Window::Width() / 2, (title.size + text.size) * 2 }, Color(0, 0, 0));
	subtitle(L"やり方").drawCenter({ Window::Width() / 2, (title.size + text.size + subtitle.size) * 2 }, Color(0, 0, 0));
	button_m.update();
}

// 毎フレーム update() の次に呼ばれる
void Rule::draw() const
{
	//back.draw(backbutton?Palette::Yellow:Palette::Black);
	//font.drawCenter(L"戻る", {Window::Width()/2,Window::Height()/2-30},Palette::White);
	button_m.draw();
	clickable::Button::drawEffect();
	Cir::drawEffect();
}