#include "Game1.h"


Game1::Game1() : memory_m(), beat_m(100, 160)
{
}

void Game1::init()
{
	memory_m.init();
	sound = Dialog::OpenSound();
	sound.play();
}

void Game1::update()
{
	static int count = 0;
	static Font font;
	const auto b = beat_m(sound, 4, 4);
	const auto fft = FFT::Analyze(sound);
	static int nowBeat;
	static int prevBeat;

	for(auto i : step(160)) {
		RectF(i * 8, Window::Height(), 8, -Pow(fft.buffer[i], 0.6f) * 2000).draw(HSV(240 - i * 2));
	}
	Rect({0, 0}, Window::Size()).draw(Color(Palette::Black, 230));

	font(Profiler::FPS()).draw(0, 680);

	prevBeat = nowBeat;
	nowBeat = b.beat;
	bool flag = (nowBeat != prevBeat && (nowBeat == 0 || nowBeat == 2));
	if(flag) {
		memory_m.alloc();
	}

	memory_m.free();
}

void Game1::draw() const
{
	memory_m.draw();
}