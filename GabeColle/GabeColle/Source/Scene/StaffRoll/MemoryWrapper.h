#pragma once

#include <Siv3D.hpp>

#include "../../GC/Memory.h"
#include "../GameData.h"
#include "CircleObject.h"

namespace staffroll{
	class MemoryWrapper
	{
	private:
		static const double MEMORY_RADIUS;
		static const double ROOT_RADIUS;
	private:
		gc::Memory<CircleObject> memory_m;
	public:
		MemoryWrapper();
	public:
		void init();
		void update();
		void draw() const;
		void alloc();
		void free(int i);
		std::vector<int> getExistAddress();
	private:		
		void randomLink(int allocAddress);
		void drawMemory() const;
		void drawArrow() const;
	};
}


