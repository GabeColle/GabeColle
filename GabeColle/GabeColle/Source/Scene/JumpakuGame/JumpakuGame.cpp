#include "JumpakuGame.h"


JumpakuGame::JumpakuGame()
	: memory_m(100 + 1)
{}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void JumpakuGame::init()
{
	memory_m.root().initialize(0);
}

// 毎フレーム updateAndDraw() で呼ばれる
void JumpakuGame::update()
{
	memory_m.root().update();
	++frame_m;
	if (Input::KeySpace.clicked) {
		auto p = memory_m.alloc();
		if (p != 0) {
			memory_m.access(p).initialize(p);
		}
	}
	for (int i(1); i < memory_m.size(); ++i) {
		if (!memory_m.hasExpired(i) && memory_m.access(i).isClicked()) {
			memory_m.access(i).finalize();
			memory_m.free(i);
		}
	}
	for (int i(1); i < memory_m.size(); ++i) {
		if (!memory_m.hasExpired(i)) {
			memory_m.access(i).update();
		}
	}
}

// 毎フレーム update() の次に呼ばれる
void JumpakuGame::draw() const
{
	drawMemory(memory_m);
}

void JumpakuGame::drawMemory(gc::Memory<clickable::CircleObject> const &memory)const
{
	//オブジェクトを描く
	memory.root().draw();
	for (int i(1); i < memory.size(); ++i) {
		if (!memory_m.hasExpired(i)) {
			memory.access(i).draw();
		}
	}

	//ルートからの参照を描く
	auto rm = memory.getRelation();
	for (int j(1); j < memory.size(); ++j) {
		if (rm.areLinked(0, j)) {
			Line(memory.root().center(), memory.access(j).center()).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
		}
		else if (rm.areLinked(j, 0)) {
			Line(memory.access(j).center(), memory.root().center()).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
		}
	}

	//オブジェクト同士の参照を描く
	auto drawArrow = [&memory] (int i, int j)
	{
		auto const &relation = memory.getRelation();
		if (relation.areLinked(i, j)) {
			Vec2 const &iCenter = memory.access(i).center();
			Vec2 const &jCenter = memory.access(j).center();
			static Color const clr = Color(Palette::Yellow, 128);
			if (i == j) {
				Circle(Vec2(40.0, -40.0).movedBy(iCenter), 40.0).drawArc(-Math::Pi / 2.0, 3.0 / 2.0 * Math::Pi, 2.0, 2.0, clr);
				Line(Vec2(0.0, -40.0).movedBy(iCenter), iCenter).drawArrow(4, { 20, 50 }, clr);
				Line(Vec2(40.0, 0.0).movedBy(iCenter), iCenter).draw(4, clr);
			}
			else {
				Line(iCenter, jCenter).drawArrow(4, { 20, 50 }, clr);
			}
		}
	};
	for (int i(1); i < memory.size(); ++i) {
		for (int j(1); j < memory.size(); ++j) {
			drawArrow(i, j);
		}
	}
}