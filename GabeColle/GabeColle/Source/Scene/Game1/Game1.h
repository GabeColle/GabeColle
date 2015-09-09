#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <vector>
#include <list>
#include <algorithm>

#include "../GameData.h"
#include "../Result/Result.h"
#include "MemoryWrapper.h"
#include "Beat.h"
#include "MySound.h"


class Game1 :
	public SceneManager<String, GameData>::Scene
{
private:
	MemoryWrapper memory_m;
	MySound sound_m;
	Beat beat_m;
public:
	Game1();
public:
	void init() override;
	void update() override;
	void draw() const override;
};