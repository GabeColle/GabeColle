#include "Result.h"

Result::Result() : resultText(25)
{

}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Result::init()
{
}

// 毎フレーム updateAndDraw() で呼ばれる
void Result::update()
{

}

// 毎フレーム update() の次に呼ばれる
void Result::draw() const
{
	resultText(resultSentence).draw(0,0,Palette::White,2.2);
	resultText(resultValues).draw(0, 50, Palette::Tomato, 2.2);
	
}