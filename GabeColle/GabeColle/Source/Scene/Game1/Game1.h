#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>

#include "../GameData.h"
#include "../../GC/Memory.h"
#include "CircleObject.h"


class Game1 :
	public SceneManager<String, GameData>::Scene
{
private:
	gc::Memory<CircleObject> memory_m;
public:
	Game1();
	void init() override;
	void update() override;
	void draw() const override;
private:
	void drawMemory(gc::Memory<CircleObject> &memory);
};