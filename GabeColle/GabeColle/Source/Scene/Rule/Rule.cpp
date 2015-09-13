#include "Rule.h"

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Rule::init()
{
	Graphics::SetBackground({ 143, 255, 239 });
	title = Font(70);
	subtitle = Font(40);
	text = Font(20);
	mainimage = Texture(L"Asset/Image/ruletext.png");
	for (int i = 0; i < 20; i++){
		cir[i] = Cir(Random(0,Window::Width()),Random(0,Window::Height()), 30, (2 * (i+1))%5);
	}
	back = Circle(Window::Width() / 2, Window::Height() / 2-30, 40);
	font = Font(20);
	click = Font(10);
}

// 毎フレーム updateAndDraw() で呼ばれる
void Rule::update()
{
	mainimage.drawAt(Window::Width()/2,Window::Height()*3/4);

	title(L"ルール！").drawCenter({ Window::Width() / 2, title.size }, Color(255, 0, 0));
	text(L"これはガベージコレクションをするゲームです").drawCenter({ Window::Width() / 2, (title.size + text.size) * 2 }, Color(0, 0, 0));
	subtitle(L"やり方").drawCenter({ Window::Width() / 2, (title.size + text.size + subtitle.size) * 2 }, Color(0, 0, 0));

	for (int i = 0; i < 20; i++){
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
}

// 毎フレーム update() の次に呼ばれる
void Rule::draw() const
{
	back.draw(backbutton?Palette::Yellow:Palette::Black);
	font.drawCenter(L"戻る", {Window::Width()/2,Window::Height()/2-30},Palette::White);
}