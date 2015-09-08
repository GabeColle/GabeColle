#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <vector>
#include <list>
#include <algorithm>

#include "../GameData.h"
#include "../../GC/Memory.h"
#include "CircleObject.h"
#include "PositionList.h"


class Game1 :
	public SceneManager<String, GameData>::Scene
{
private:
	static const double MEMORY_RADIUS;
	static const double ROOT_RADIUS;
private:
	gc::Memory<CircleObject> memory_m;
	PositionList positionList_m;
public:
	Game1();
	void init() override;
	void update() override;
	void draw() const override;
private:
	void drawMemory() const;
	std::vector<int> getExistAddress();
	void randomLink(int allocAddress);
};