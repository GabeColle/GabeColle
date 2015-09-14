#include "MemoryWrapper.h"

using namespace staffroll;

const double MemoryWrapper::MEMORY_RADIUS = 40.0;
const double MemoryWrapper::ROOT_RADIUS = 50.0;
const int MemoryWrapper::FREE_INTERVAL = 10;


MemoryWrapper::MemoryWrapper() : memory_m(40), positionList_m()
{
}


void MemoryWrapper::init()
{
	memoryFreeTimer_m = FREE_INTERVAL;
	memory_m.root().setCenter(positionList_m.getRootPos());
}

void MemoryWrapper::alloc()
{
	int address = memory_m.alloc();
	if (address != 0) {
		memory_m.access(address).setCenter(Vec2(Random(0 + 100, (int)Window::Width() - 100), Random(0 + 100, (int)Window::Height()-100)));
		randomLink(address);
	}
}

void MemoryWrapper::free(int i)
{
	if (memoryFreeTimer_m == 0){
		if (!memory_m.hasExpired(i)) {
			positionList_m.restoreRandomPos(memory_m.access(i).getCenter());
			memory_m.free(i);
			memoryFreeTimer_m = 0;
		}
	}
	else{
		memoryFreeTimer_m--;
	}
	
}

void MemoryWrapper::update()
{
}

void MemoryWrapper::draw() const
{
	drawMemory();
	drawArrow();
}



void MemoryWrapper::randomLink(int allocAddress)
{
	int from = -1;	// 出発地
	int to = -1;	// 目的地
	if (RandomBool(0.7)) {
		std::vector<int> numList = getExistAddress();
		std::random_shuffle(numList.begin(), numList.end());
		if (RandomBool(0.5)) {
			from = numList[0];
			to = allocAddress;
		}
		else {
			from = allocAddress;
			to = numList[0];
		}
	}
	if (from != -1 && to != -1) {
		memory_m.link(from, to);
	}
}


std::vector<int> MemoryWrapper::getExistAddress()
{
	std::list<int> numList(0);
	for (int i(1); i < memory_m.size(); ++i) {
		if (!memory_m.hasExpired(i)) {
			numList.push_back(i);
		}
	}
	std::vector<int> numVector(numList.begin(), numList.end());
	return numVector;
}

void MemoryWrapper::drawMemory() const
{
	static const Font font;

	//オブジェクトを描く
	auto drawCircle = [this](int address) {
		if (!memory_m.hasExpired(address)) {
			Circle c = Circle(memory_m.access(address).getCenter(), MEMORY_RADIUS);
			c.draw(Color(Palette::Red, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
			font.drawCenter(ToString(address), c.center);
		}
	};
	for(int i(1); i < memory_m.size(); ++i) {
		drawCircle(i);
	}
}

void MemoryWrapper::drawArrow() const
{
	static const Font font;

	//オブジェクト同士の参照を描く
	auto drawArrow = [this](int i, int j) {
		auto const &relation = memory_m.getRelation();
		if(relation.areLinked(i, j)) {
			Vec2 const &iCenter = memory_m.access(i).getCenter();
			Vec2 const &jCenter = memory_m.access(j).getCenter();
			static Color const clr = Color(Palette::Yellow, 128);
			if(i == j) {
				Circle(Vec2(40.0, -40.0).movedBy(iCenter), 40.0).drawArc(-Math::Pi / 2.0, 3.0 / 2.0 * Math::Pi, 2.0, 2.0, clr);
				Line(Vec2(0.0, -40.0).movedBy(iCenter), iCenter).drawArrow(4, {20, 50}, clr);
				Line(Vec2(40.0, 0.0).movedBy(iCenter), iCenter).draw(4, clr);
			} else {
				Line(iCenter, jCenter).drawArrow(4, {20, 50}, clr);
			}
		}
	};
	for(int i(1); i < memory_m.size(); ++i) {
		for(int j(1); j < memory_m.size(); ++j) {
			drawArrow(i, j);
		}
	}
}