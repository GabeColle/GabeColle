#include "Game1.h"


Game1::Game1()
	: memory_m()
	, sound_m(L"./Asset/BGM/歌舞伎ダンシング_2.ogg", L"Game1BGM")
	, beat_m(L"Game1BGM", 160)
	, BEAT(2)
	, STAGE_NAME(L"Game1(Normal)")
{
}

Game1::Game1(const FilePath BGMPath, const String BGMName, const int32 tempo, const int beat, const String stageName)
	: memory_m()
	, sound_m(BGMPath, BGMName)
	, beat_m(BGMName, tempo)
	, BEAT(beat)
	, STAGE_NAME(stageName)
{
}

void Game1::init()
{
	memory_m.init(STAGE_NAME);
	sound_m.startMusic();
}

void Game1::update()
{
	// 拍カウントの更新処理
	beat_m.update();
	// 拍が切り替わった時にメモリ生成
	if(beat_m.getBeatRising(BEAT)) { memory_m.alloc(); }

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
	sound_m.drawSpectrum();
	memory_m.draw();
}