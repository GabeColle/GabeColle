#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

#include"../../GC/Memory.h"
//#include"Game2Memory.h"
#include"CircleObject.h"
#include"../../Utility/Button/Button.h"

namespace game2{

class Game2 :
	public SceneManager<String, GameData>::Scene
{
private:
	gc::Memory<CircleObject> memory_m;
	Button button_m;

	const int NUM_OF_MEMORY = 18;

	unsigned int time_m;
	unsigned int count_m;
	int garbage_m;
	int segmentFault_m;

	const Vec2 rootPos = { Window::Width() / 2.0, Window::Height() / 2.0 };	

	enum class State{
		draw = 0, MtoM ,erase, input, result,
	}state;

public:
	//コンストラクタ
	Game2() : memory_m(19),
		      button_m(30,L"OK",100,100){};

	//デストラクタ
	~Game2(){};

	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;

private:
	int alloc(Vec2 pos);
	bool allocAndReferenceFromRoot(Vec2 pos);
	bool allocAndRefetenceMemoryToMemory(int address_t,Vec2 pos);

	void freeByInput();
	void countAndChangeState(bool isOutOfMemory);
	void seekSegmentFault();
};

}