#include "Rule.h"

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Rule::init()
{
	Graphics::SetBackground({ 143, 255, 239 });
	title = Font(70);
	subtitle = Font(40);
	text = Font(20);
	ruleText1 = L"これはガベージコレクションをするゲームです";
	Println(Window::Height());
}

// 毎フレーム updateAndDraw() で呼ばれる
void Rule::update()
{
	player = Circle(Mouse::Pos(),1);
}

// 毎フレーム update() の次に呼ばれる
void Rule::draw() const
{
	title(L"ルール！").drawCenter({ Window::Width()/2, title.size }, Color(255,0,0));
	text(ruleText1).drawCenter({ Window::Width() / 2, (title.size + text.size) * 2 }, Color(0, 0, 0));
	subtitle(L"やり方").drawCenter({ Window::Width() / 2, (title.size + text.size + subtitle.size) * 2 }, Color(0, 0, 0));

}