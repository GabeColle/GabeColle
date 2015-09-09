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
	for (int i(0); i < 10; ++i) {
		auto p = memory_m.alloc();
		memory_m.access(p).initialize(p);
	}

	gameOverFont_m = Font(100, Typeface::Black, FontStyle::Outline);
	gameOverFont_m.changeOutlineStyle(TextOutlineStyle(Palette::Black, Color(Palette::Red).setAlpha(167), 3.0));

	gameOverMessageFont_m = Font(30, Typeface::Medium, FontStyle::Outline);
	gameOverMessageFont_m.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::Red, 1.0));
}

// 毎フレーム updateAndDraw() で呼ばれる
void JumpakuGame::update()
{
	++frame_m;

	switch (state_m) {
	case JumpakuGame::GAME_OVER:
		updateGameOver();
		break;
	case JumpakuGame::VALID:
		updateObjects();
		break;
	case JumpakuGame::CLEAR:
		break;
	default:
		break;
	}
	checkState();
}

// 毎フレーム update() の次に呼ばれる
void JumpakuGame::draw() const
{
	drawMemory();
	switch (state_m) {
	case JumpakuGame::GAME_OVER:
		drawGameOver();
		break;
	case JumpakuGame::CLEAR:
		break;
	case JumpakuGame::VALID:
		break;
	default:
		break;
	}
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
			++deletes_m;
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
		int i = Random(0, SIZE_m - 1);
		int j = Random(0, SIZE_m - 1);
		if ((i == 0 || (i != 0 && !memory_m.hasExpired(i) && !memory_m.access(i).isFreed())) &&
			(j == 0 || (j != 0 && !memory_m.hasExpired(j) && !memory_m.access(j).isFreed()))) {
			memory_m.unlink(i, j);
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
	auto const &relation = memory_m.getRelation();
	for (int i(0); i < memory_m.size(); ++i) {
		for (int j(0); j < memory_m.size(); ++j) {
			if (relation.areLinked(i, j)) {
				linkArrowTable_m[i][j].draw();
			}
		}
	}
}

void JumpakuGame::checkState()
{
	auto e = memory_m.error();
	if (e.outOfMemory_m > 0 || e.segmentationFault_m > 0) {
		state_m = GAME_OVER;
		initGameOver(e);
		saveScore();
	}
	else if (frame_m > CLEAR_LIMIT_m) {
		state_m = CLEAR;
		saveScore();
		setMessage(L"Success");
	}
}

void JumpakuGame::saveScore()
{
	auto const &e = memory_m.error();
	m_data->numOfError = e.addressOutOfBounds_m + e.nullptrAccess_m + e.outOfMemory_m + e.segmentationFault_m;
	m_data->stageName = L"Stage0";
	m_data->numOfDeletedObject = deletes_m;
	m_data->time = frame_m;
	m_data->totalScore = e.outOfMemory_m * -3000 + e.segmentationFault_m * -4000 + deletes_m*50 + frame_m * 5;
}




void JumpakuGame::updateGameOver()
{
	gameOverButtons_m.at(L"Garbage Collection")->update();
	gameOverButtons_m.at(L"Result")->update();

	if (gameOverButtons_m.at(L"Garbage Collection")->isClicked()) {
		memory_m.gc();
	}
	if (gameOverButtons_m.at(L"Result")->isClicked()) {
		//changeScene(L"Result");
	}
}

void JumpakuGame::drawGameOver()const
{
	Rect(Window::ClientRect()).draw(HSV(180.0, 0.9, 0.9).toColor(127));
	gameOverFont_m(L"GAME OVER").drawCenter(Window::Center().movedBy(0, -100));
	gameOverMessageFont_m(message_m).drawCenter(Window::Center().movedBy(0, 60));
	gameOverButtons_m.at(L"Garbage Collection")->draw();
	gameOverButtons_m.at(L"Result")->draw();

}

void JumpakuGame::initGameOver(gc::Error const &e)
{
	setMessage(e.outOfMemory_m > 0 ? L"Out of Memory" : L"Segmentation Fault");
	auto addButton = [this] (Point p, String name, String sound)
	{
		auto btn = std::make_shared<clickable::Button>(Rect(500, 60).setCenter(p), name, sound);
		btn->show();
		gameOverButtons_m.insert(std::make_pair(name, btn));
	};
	addButton(Window::Center().movedBy(0, 140), L"Garbage Collection", L"Asset/SoundEffect/Decision.mp3");
	addButton(Window::Center().movedBy(0, 230), L"Result", L"Asset/SoundEffect/Decision.mp3");
}

void JumpakuGame::setMessage(String const &m)
{
	message_m = m;
}