#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include <vector>
#include <list>
#include <algorithm>

#include "../GameData.h"
#include "../../GC/Memory.h"
#include "CircleObject.h"


class Game1 :
	public SceneManager<String, GameData>::Scene
{
private:
	static const double MEMORY_RADIUS;
	static const double ROOT_RADIUS;
	static const int POSITION_NUM_X;
	static const int POSITION_NUM_Y;
	static const int POSITION_MARGIN_X;
	static const int POSITION_MARGIN_Y;
private:
	gc::Memory<CircleObject> memory_m;
	std::list<Vec2> positionList_m;
public:
	Game1();
	void init() override;
	void update() override;
	void draw() const override;
private:
	void initializePositionList();
	void drawMemory() const;
	std::vector<int> getExistAddress();
	void randomLink(int allocAddress);
};