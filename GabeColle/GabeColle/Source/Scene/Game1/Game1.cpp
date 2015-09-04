#include "Game1.h"


Game1::Game1() : memory_m(100 + 1)
{
}

void Game1::init()
{
	
}

void Game1::update()
{
	if(Mouse::LeftClicked()) {
		int address = memory_m.alloc();
		if(address != 0) {
			memory_m.access(address).setCenter(RandomVec2({200, 600}, {50, Window::Height() - 50}));
		}
	}
	drawMemory(memory_m);
}

void Game1::draw() const
{
}

void Game1::drawMemory(gc::Memory<CircleObject> &memory)
{
	static Font font;
	font.drawCenter(L"Root", Circle(memory.root().getCenter(), 50.0).draw(Palette::Aqua).center);

	//オブジェクトを描く
	auto drawCircle = [&memory](int address) {
		double const r = 40.0;
		if(!memory.hasExpired(address)) {
			Circle c = Circle(memory.access(address).getCenter(), r);
			if(c.leftClicked) {
				memory.free(address);
			} else if(c.mouseOver) {
				c.draw(Color(Palette::Pink, 128)).drawFrame(0.0, 3.0, Palette::Red);
			} else {
				c.draw(Color(Palette::Red, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
			}
			font.drawCenter(ToString(address), c.center);
		}
	};
	for(int i(1); i < memory.size(); ++i) {
		drawCircle(i);
	}

	//ルートからの参照を描く
	auto rm = memory.getRelation();
	for(int j(1); j < memory.size(); ++j) {
		if(rm.areLinked(0, j)) {
			Line(memory.root().getCenter(), memory.access(j).getCenter()).drawArrow(4, {20, 50}, Color(Palette::Yellow, 128));
		} else if(rm.areLinked(j, 0)) {
			Line(memory.access(j).getCenter(), memory.root().getCenter()).drawArrow(4, {20, 50}, Color(Palette::Yellow, 128));
		}
	}

	//オブジェクト同士の参照を描く
	auto drawArrow = [&memory](int i, int j) {
		auto rm = memory.getRelation();
		if(rm.areLinked(i, j)) {
			Vec2 const &iCenter = memory.access(i).getCenter();
			Vec2 const &jCenter = memory.access(j).getCenter();
			Color clr = Color(Palette::Yellow, 128);
			if(i == j) {
				Circle(Vec2(40.0, -40.0).movedBy(iCenter), 40.0).drawArc(-Math::Pi / 2.0, 3.0 / 2.0 * Math::Pi, 2.0, 2.0, clr);
				Line(Vec2(0.0, -40.0).movedBy(iCenter), iCenter).drawArrow(4, {20, 50}, clr);
				Line(Vec2(40.0, 0.0).movedBy(iCenter), iCenter).draw(4, clr);
			} else {
				Line(iCenter, jCenter).drawArrow(4, {20, 50}, clr);
			}
		}
	};
	/*
	for(int i(1); i < memory.size(); ++i) {
		for(int j(1); j < memory.size(); ++j) {
			drawArrow(i, j);
		}
	}
	*/
}