#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"
#include"../../GC/Memory.h"
#include"../../Clickable/CircleObject.h"

class JumpakuGame :
	public SceneManager<String, GameData>::Scene
{
	gc::Memory<clickable::CircleObject> memory_m;
	void drawMemory(gc::Memory<clickable::CircleObject> const &memory)const;

public:
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override
	{
		memory_m.root().alloc(0);
	}

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override
	{
		memory_m.root().update();
		if (Mouse::LeftClicked()) {
			auto p = memory_m.alloc();
			if (p != 0) {
				memory_m.access(p).alloc(p);
			}
		}
		for (int i(1); i < memory_m.size(); ++i) {
			if (!memory_m.hasExpired(i)) {
				memory_m.access(i).update();
			}
		}
	}

	// 毎フレーム update() の次に呼ばれる
	void draw() const override
	{
		drawMemory(memory_m);
	}
	JumpakuGame();
	~JumpakuGame() = default;
};

