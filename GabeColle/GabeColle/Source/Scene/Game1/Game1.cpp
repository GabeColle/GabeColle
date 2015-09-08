#include "Game1.h"


Game1::Game1() : memory_m()
{
}

void Game1::init()
{
	memory_m.init();
}

void Game1::update()
{
	static int count = 0;
	static Font font;

	font(Profiler::FPS()).draw(0, 680);

	if(count > 30) {
		memory_m.alloc();
		count = 0;
	}
	++count;
	memory_m.free();
}

void Game1::draw() const
{
	memory_m.draw();
}