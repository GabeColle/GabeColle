#include "JumpakuGame.h"
#include"../../Clickable/Button.h"

JumpakuGame::JumpakuGame()
	: memory_m(SIZE_m)
{}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void JumpakuGame::init()
{
	Graphics::SetBackground(Palette::Whitesmoke);

	memory_m.root().initialize(0);
	for (int i(0); i < 100; ++i) {
		auto p = memory_m.alloc();
		memory_m.access(p).initialize(p);
	}
}

// 毎フレーム updateAndDraw() で呼ばれる
void JumpakuGame::update()
{
	++frame_m;

	//GC
	if (Input::KeyG.clicked) {
		memory_m.gc();
	}
	switch (state_m) {
	case JumpakuGame::SEGMENTATION_FAULT:

		break;
	case JumpakuGame::OUT_OF_MEMORY:
		
		break;
	case JumpakuGame::VALID:
		updateObjects();
		break;
	default:
		break;
	}
	checkState();
}

void JumpakuGame::updateObjects()
{
	//alloc
	if (frame_m%allocInterval_m == 0) {
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
	if (frame_m%objectLinkInterval_m == 0) {
		int i = Random(0, SIZE_m - 1);
		int j = Random(0, SIZE_m - 1);
		if ((i == 0 || (i != 0 && !memory_m.hasExpired(i) && !memory_m.access(i).isFreed())) &&
			(j == 0 || (j != 0 && !memory_m.hasExpired(j) && !memory_m.access(j).isFreed()))) {
			memory_m.link(i, j);
		}
	}
	if (frame_m%rootLinkInterval_m == 1) {
		int i = Random(0, SIZE_m - 1);
		if ((i == 0 || (i != 0 && !memory_m.hasExpired(i) && !memory_m.access(i).isFreed()))) {
			memory_m.link(0, i);
		}
	}
	if (frame_m%unlinkInterval_m == 0) {
		for (int k(0); k < 20; ++k) {
			int i = Random(0, SIZE_m - 1);
			int j = Random(0, SIZE_m - 1);
			if ((i == 0 || (i != 0 && !memory_m.hasExpired(i) && !memory_m.access(i).isFreed())) &&
				(j == 0 || (j != 0 && !memory_m.hasExpired(j) && !memory_m.access(j).isFreed()))) {
				memory_m.unlink(i, j);
			}
		}
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
			if (relation.areLinked(i, j)) {
				if (!linkArrowTable_m[i][j].isVisible()) {
					if (i == 0) {

					}
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
}

// 毎フレーム update() の次に呼ばれる
void JumpakuGame::draw() const
{
	drawMemory();
	static Font const font100(100);
	static Font const font20(20);
	switch (state_m) {
	case JumpakuGame::SEGMENTATION_FAULT:
		Rect(Window::ClientRect()).draw(HSV(180.0, 0.9, 0.9).toColor(127));
		font100(L"GAME OVER").drawCenter(Window::Center().movedBy(0, -100), Palette::Red);
		font20(L"ERROR : Segmentation Fault").drawCenter(Window::Center().movedBy(0, 100), Palette::Black);
		break;
	case JumpakuGame::OUT_OF_MEMORY:
		Rect(Window::ClientRect()).draw(HSV(180.0, 0.9, 0.9).toColor(127));
		font100(L"GAME OVER").drawCenter(Window::Center().movedBy(0, -100), Palette::Red);
		font20(L"ERROR : Out of Memory").drawCenter(Window::Center().movedBy(0, 100), Palette::Black);
		break;
	case JumpakuGame::VALID:
		break;
	default:
		break;
	}
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
			linkArrowTable_m[i][j].draw();
		}
	};
	for (int i(0); i < memory_m.size(); ++i) {
		for (int j(0); j < memory_m.size(); ++j) {
			drawArrow(i, j);
		}
	}
}

void JumpakuGame::checkState()
{
	auto e = memory_m.error();
	if (e.outOfMemory_m > 0) {
		state_m = OUT_OF_MEMORY;
	}
	else if (e.segmentationFault_m > 0) {
		state_m = SEGMENTATION_FAULT;
	}
}

void JumpakuGame::drawError()const
{

}
