#include "Sample.h"

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Sample::init()
{
	texture_m = Texture(L"Asset/Image/GabeColle.png");
}

// 毎フレーム updateAndDraw() で呼ばれる
void Sample::update()
{

}

// 毎フレーム update() の次に呼ばれる
void Sample::draw() const
{
	texture_m.drawAt(Window::Center());
}