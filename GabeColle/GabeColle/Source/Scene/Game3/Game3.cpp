#include<typeinfo>
#include "Game3.h"
#include"../../Clickable/Button.h"
#include"GameOver.h"
#include"Clear.h"
#include"Playing.h"

String const Game3::SceneState::nextScene_m = L"Result";
String const Game3::gameOverSound_m = L"Asset/SoundEffect/GameOver.mp3";
String const Game3::clearSound_m = L"Asset/SoundEffect/clear.mp3";
String const Game3::bgm_m = L"Asset/BGM/Game3BGM.mp3";

Game3::Game3(int clearLimit, int allocInterval, int objectLinkInterval, int rootLinkInterval, int unlinkInterval)
	: clearLimit_m(clearLimit),
	allocInterval_m(allocInterval),
	objectLinkInterval_m(objectLinkInterval),
	rootLinkInterval_m(rootLinkInterval),
	unlinkInterval_m(unlinkInterval),
	memory_m(SIZE_m)
{
	if (!SoundAsset::IsRegistered(gameOverSound_m)) {
		SoundAsset::Register(gameOverSound_m, gameOverSound_m);
	}
	if (!SoundAsset::IsRegistered(clearSound_m)) {
		SoundAsset::Register(clearSound_m, clearSound_m);
	}
	if (!SoundAsset::IsRegistered(bgm_m)) {
		SoundAsset::Register(bgm_m, bgm_m);
	}
	SoundAsset(bgm_m).setLoop(true);
	SoundAsset(bgm_m).play();
}


// クラスの初期化時に一度だけ呼ばれる（省略可）
void Game3::init()
{
	Graphics::SetBackground(Palette::Whitesmoke);
	
	memory_m.root().initialize(0, objectEffect_m);
	for (int i(0); i < 10; ++i) {
		auto p = memory_m.alloc();
		memory_m.access(p).initialize(p, objectEffect_m);
	}
	sceneState_m = std::make_shared<Playing>();
}

// 毎フレーム updateAndDraw() で呼ばれる
void Game3::update()
{
	++frame_m;
	sceneState_m->update(*this);
	checkState();
}

// 毎フレーム update() の次に呼ばれる
void Game3::draw() const
{
	drawMemory();
	sceneState_m->draw();
	objectEffect_m.update();
}


void Game3::updateMemory()
{
	//alloc
	if (frame_m%allocInterval_m == 0) {
		auto p = memory_m.alloc();
		if (p != 0) {
			memory_m.access(p).initialize(p, objectEffect_m);
		}
	}
	//free
	for (int i(1); i < SIZE_m; ++i) {
		if (!memory_m.hasExpired(i) && memory_m.access(i).isClicked()) {
			memory_m.access(i).finalize(objectEffect_m);
			memory_m.free(i);
			++deletes_m;
		}
	}
	//link,unlink	
	if (frame_m%objectLinkInterval_m == 0) {
		int i = Random(0, SIZE_m - 1);
		int j = Random(0, SIZE_m - 1);
		if ((i == 0 || (i != 0 && !memory_m.hasExpired(i))) &&
			(j == 0 || (j != 0 && !memory_m.hasExpired(j)))) {
			memory_m.link(i, j);
		}
	}
	if (frame_m%rootLinkInterval_m == 1) {
		int i = Random(0, SIZE_m - 1);
		if ((i == 0 || (i != 0 && !memory_m.hasExpired(i)))) {
			memory_m.link(0, i);
		}
	}
	if (frame_m%unlinkInterval_m == 0) {
		int i = Random(0, SIZE_m - 1);
		int j = Random(0, SIZE_m - 1);
		if ((i == 0 || (i != 0 && !memory_m.hasExpired(i))) &&
			(j == 0 || (j != 0 && !memory_m.hasExpired(j)))) {
			memory_m.unlink(i, j);
		}
	}
	//update object
	for (int i(1); i < SIZE_m; ++i) {
		if (!memory_m.hasExpired(i)) {
			memory_m.access(i).update();
		}
	}
	//update arrow
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

void Game3::drawMemory()const
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

void Game3::checkState()
{
	auto e = memory_m.error();
	if (typeid(*sceneState_m.get()) != typeid(GameOver) &&
		(e.outOfMemory_m > 0 || e.segmentationFault_m > 0)) {
		sceneState_m = std::make_shared<GameOver>(
			e.outOfMemory_m > 0 ? L"Out of Memory" : L"Segmentation Fault");
		SoundAsset(bgm_m).stop();
		SoundAsset(gameOverSound_m).play();
		saveScore();
	}
	else if (typeid(*sceneState_m.get()) != typeid(Clear) &&
		frame_m > clearLimit_m) {
		sceneState_m = std::make_shared<Clear>();
		SoundAsset(bgm_m).stop();
		SoundAsset(clearSound_m).play();
		saveScore();
	}
}

void Game3::saveScore()
{
	auto const &e = memory_m.error();
	m_data->numOfError = e.addressOutOfBounds_m + e.nullptrAccess_m + e.outOfMemory_m + e.segmentationFault_m;
	m_data->stageName = L"Game3";
	m_data->numOfDeletedObject = deletes_m;
	m_data->time = frame_m;
	m_data->totalScore = 
		e.outOfMemory_m * -2000 + e.segmentationFault_m * -3000 + deletes_m*30 + frame_m * 1;
}

/*void Game3::showResult()
{
	SoundAsset(bgm_m)
}*/
