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
	long frame_m = 0;
public:
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;

	JumpakuGame();
	~JumpakuGame() = default;
};

