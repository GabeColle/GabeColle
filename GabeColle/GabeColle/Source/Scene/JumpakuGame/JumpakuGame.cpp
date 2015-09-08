#include "JumpakuGame.h"


JumpakuGame::JumpakuGame()
	: memory_m(SIZE_m)
{}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void JumpakuGame::init()
{
	Graphics::SetBackground(Palette::Whitesmoke);

	memory_m.root().initialize(0);
}

// 毎フレーム updateAndDraw() で呼ばれる
void JumpakuGame::update()
{
	memory_m.root().update();
	++frame_m;
	//alloc
	if (frame_m%1==0) {
		auto p = memory_m.alloc();
		if (p != 0) {
			memory_m.access(p).initialize(p);
		}
	}
	//free
	for (int i(1); i < SIZE_m; ++i) {
		if (!memory_m.hasExpired(i) && memory_m.access(i).isClicked()) {
			memory_m.access(i).finalize();
			memory_m.free(i);
		}
	}
	//link,unlink
	
	if (Input::KeyL.pressed) {
		memory_m.link(Random(0, SIZE_m - 1), Random(0, SIZE_m - 1));
	}
	for (int i(100); --i;) {
		memory_m.unlink(Random(0, SIZE_m - 1), Random(0, SIZE_m - 1));
	}
	//update object
	for (int i(1); i < SIZE_m; ++i) {
		if (!memory_m.hasExpired(i)) {
			memory_m.access(i).update();
		}
	}
	//update allow
	gc::Relation const &relation = memory_m.getRelation();
	for (int i(0); i < SIZE_m; ++i) {
		for (int j(0); j < memory_m.size(); ++j) {
			if (relation.areLinked(i, j)){
				if (!linkArrowTable_m[i][j].isVisible()) {
					auto const & from = i != 0 ? memory_m.access(i) : memory_m.root();
					auto const & to = j != 0 ? memory_m.access(j) : memory_m.root();
					linkArrowTable_m[i][j].show(from.center(), to.center());
				}
			}
			else {
				linkArrowTable_m[i][j].hide();
			}
		}
	}
	//GC
	if (Input::KeyG.clicked) {
		memory_m.gc();
	}
}

// 毎フレーム update() の次に呼ばれる
void JumpakuGame::draw() const
{
	drawMemory();
}

void JumpakuGame::drawMemory()const
{
	//オブジェクトを描く
	memory_m.root().draw();
	for (int i(1); i < memory_m.size(); ++i) {
		if (!memory_m.hasExpired(i)) {
			memory_m.access(i).draw();
		}
	}

	//オブジェクト同士の参照を描く
	auto drawArrow = [this] (int i, int j)
	{
		auto const &relation = memory_m.getRelation();
		if (relation.areLinked(i, j)) {
			this->linkArrowTable_m[i][j].draw();
		}
	};
	for (int i(1); i < memory_m.size(); ++i) {
		for (int j(1); j < memory_m.size(); ++j) {
			drawArrow(i, j);
		}
	}
}