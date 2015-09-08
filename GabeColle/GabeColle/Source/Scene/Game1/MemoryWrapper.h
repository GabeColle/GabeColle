#pragma once

#include <Siv3D.hpp>

#include "../../GC/Memory.h"
#include "CircleObject.h"
#include "PositionList.h"


class MemoryWrapper
{
private:
	static const double MEMORY_RADIUS;
	static const double ROOT_RADIUS;
private:
	gc::Memory<CircleObject> memory_m;
	PositionList positionList_m;
public:
	MemoryWrapper();
	~MemoryWrapper() = default;
public:
	void init();
	void alloc();
	bool free();
	void draw() const;
private:
	std::vector<int> getExistAddress();
	void randomLink(int allocAddress);
};

