#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

#include"../../GC/Memory.h"
#include"../../GC/GarbageCollection.h"

#include"CircleObject.h"
#include"Controller.h"

#include"../../Utility/Button/Button.h"
#include"Game2GabeColle.h"

namespace game2{

class Game2 :
	public SceneManager<String, GameData>::Scene
{
private:
	gc::Memory<CircleObject> memory_m;
	Controller gui;
	Button button_m;

	unsigned int time_m;
	unsigned int count_m;
	unsigned int lap_m;
	int radius_m;
	const Vec2 rootPos = { Window::Width() / 2.0, Window::Height() / 2.0 };

	int garbage_m;
	
	enum class Type{
		type1,type2,type3,
	}type;
	enum class State{
		draw, MtoM ,erase, tmp
	}state;
public:
	Game2() : memory_m(19),
		      button_m(30,L"OK",100,100){};
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
};

}