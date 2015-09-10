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
	// 拍カウントの更新処理
	beat_m.update();
	// 拍が切り替わった時にメモリ生成
	if(beat_m.getBeatRising()) { memory_m.alloc(); }

	// メモリの開放
	if(Mouse::LeftClicked()) { memory_m.free(); }

	// メモリの更新
	memory_m.update();

	// BGMが終了したらResult画面に飛ぶ
	if(sound_m.isEnded()) {
		*m_data = memory_m.calculateScore();
		changeScene(L"Result", 2000);
	}
}

void Game1::draw() const
{
	static Font font;
	sound_m.drawSpectrum();
	memory_m.draw();
	font(Profiler::FPS()).draw(0, 680);
}