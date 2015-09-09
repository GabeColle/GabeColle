#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <vector>
#include <list>
#include <algorithm>

#include "../GameData.h"
#include "MemoryWrapper.h"


class Game1 :
	public SceneManager<String, GameData>::Scene
{
private:
	MemoryWrapper memory_m;
	Sound sound;
	SoundBeat beat_m;
public:
	Game1();
	void init() override;
	void update() override;
	void draw() const override;
};