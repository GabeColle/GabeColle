#include "Game1.h"


Game1::Game1() : memory_m(), sound_m(), beat_m()
{
}

void Game1::init()
{
	memory_m.init();
	sound_m.startMusic();
}

void Game1::update()
{
	static Font font;
	font(Profiler::FPS()).draw(0, 680);

	// 拍カウントの更新処理
	beat_m.update();
	// 拍が切り替わった時にメモリ生成
	if(beat_m.getBeatRising()) { memory_m.alloc(); }

	//
	if(Mouse::LeftClicked()) { memory_m.free(); }

	// BGMが終了したらResult画面に飛ぶ
	if(sound_m.isEnded())  changeScene(L"Result", 2000);
}

void Game1::draw() const
{
	sound_m.drawSpectrum();
	memory_m.draw();
}