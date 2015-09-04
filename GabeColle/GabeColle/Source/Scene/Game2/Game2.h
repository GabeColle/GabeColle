#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

#include"../../GC/Memory.h"

#include"CircleObject.h"
#include"Controller.h"

class Game2 :
	public SceneManager<String, GameData>::Scene
{
private:
	gc::Memory<CircleObject> memory_m;
	Controller gui;

	unsigned time_m;
	
public:
	Game2() : memory_m(100){};
	~Game2(){};

	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;

private:
	void alloc();
};
