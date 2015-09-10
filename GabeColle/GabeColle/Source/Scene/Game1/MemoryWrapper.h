#pragma once

#include <Siv3D.hpp>

#include "../../GC/Memory.h"
#include "../GameData.h"
#include "CircleObject.h"
#include "PositionList.h"
#include "ErrorFlagManager.h"
#include "FadeOutEffect.h"
#include "OutOfEffect.h"


class MemoryWrapper
{
private:
	static const double MEMORY_RADIUS;
	static const double ROOT_RADIUS;
private:
	gc::Memory<CircleObject> memory_m;
	PositionList positionList_m;
	ErrorFlagManager errorFlag_m;
	Effect effect_m;
	GameData data_m;
public:
	MemoryWrapper();
public:
	void init();
	void update();
	void draw() const;
	void alloc();
	void free();
	GameData calculateScore();
private:
	std::vector<int> getExistAddress();
	void randomLink(int allocAddress);
	void drawMemory() const;
	void drawArrow() const;
};

