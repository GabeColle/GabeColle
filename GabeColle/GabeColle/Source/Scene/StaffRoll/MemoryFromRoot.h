#pragma once

#include <Siv3D.hpp>

#include "../../GC/Memory.h"
#include "../GameData.h"
#include "CircleObject.h"
#include "PositionList.h"
#include "../Result/FadeInAndDescendStringEffect.h"

namespace staffroll{
	class MemoryFromRoot{
	private:
		static const double MEMORY_RADIUS;
		static const double ROOT_RADIUS;
		gc::Memory<CircleObject> memory_m;
		PositionList positionList_m;
		String contentName_m;
		Array<String> parties_m;
	public:
		MemoryFromRoot(int maxMemory,String contentName,Array<String> parties);
		void update();
		void draw() const;
		void alloc();
	private:
		void intentLink(int allocAddress);
		void drawMemory() const;
		void drawArrow() const;
		void drawRoot(String content)const;
	};
}
