#include "Rule.h"

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Rule::init()
{
	Graphics::SetBackground({ 143, 255, 239 });
	title = Font(70);
	subtitle = Font(40);
	text = Font(20);
	for (int i = 0; i < 10; i++){
		cir[i] = Cir(Window::Width()/2,i*Window::Height()/10,30,20);
	}
}

// 毎フレーム updateAndDraw() で呼ばれる
void Rule::update()
{
	for (int i = 0; i < 10; i++){
		if (i % 2){
			cir[i].rightmove();
		}
		else{
			cir[i].leftmove();
		}
		cir[i].draw();
	}

}

// 毎フレーム update() の次に呼ばれる
void Rule::draw() const
{
	title(L"ルール！").drawCenter({ Window::Width()/2, title.size }, Color(255,0,0));
	text(L"これはガベージコレクションをするゲームです").drawCenter({ Window::Width() / 2, (title.size + text.size) * 2 }, Color(0, 0, 0));
	subtitle(L"やり方").drawCenter({ Window::Width() / 2, (title.size + text.size + subtitle.size) * 2 }, Color(0, 0, 0));

}