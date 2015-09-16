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
	const int BEAT;
	const String STAGE_NAME;
private:
	MemoryWrapper memory_m;
	MySound sound_m;
	Beat beat_m;
public:
	Game1();
	Game1(const FilePath BGMPath, const String BGMName, const int32 tempo, const int beat, const String stageName);
public:
	void init() override;
	void update() override;
	void draw() const override;
};


class Game1Easy : public Game1
{
public:
	Game1Easy()
		: Game1(L"./Asset/BGM/アップリフト4.ogg", L"Game1EasyBGM", 136, 1, L"Game1(Easy)")
	{
	}
};


class Game1Hard : public Game1
{
public:
	Game1Hard()
		: Game1(L"./Asset/BGM/Cyber_transformer.ogg", L"Game1HardBGM", 134, 4, L"Game1(Hard)")
	{
	}
};