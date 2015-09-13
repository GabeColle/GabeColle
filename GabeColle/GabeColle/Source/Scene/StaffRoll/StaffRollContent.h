#pragma once

#include <siv3D.hpp>
#include "MemoryWrapper.h"
#include "MemoryFromRoot.h"

class StaffRollContent
{
private:
	static const int INIT_OBJECTS;
	staffroll::MemoryWrapper memory_m;
	staffroll::MemoryFromRoot* memoryR_m;
	Array<String> parties_m;
public:
	StaffRollContent(int numOfObjectFromRoot_m, String contentName_m,Array<String> parties);
	void init();
	void update();
	void draw()const;
};