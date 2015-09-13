#include "MemoryFromRoot.h"

using namespace staffroll;

const double MemoryFromRoot::MEMORY_RADIUS = 100.0;
const double MemoryFromRoot::ROOT_RADIUS = 50.0;

MemoryFromRoot::MemoryFromRoot(int maxMemory,String contentName,Array<String> parties) : memory_m(parties.size()+1),positionList_m()
{
	memory_m.root().setCenter(positionList_m.getRootPos());
	contentName_m = contentName;
	for (int i = 0; i < parties.size(); ++i){
		parties_m.push_back(new DescendAndCountStringEffect(parties[i], 30, 30 + i * 10));
	}
}

void MemoryFromRoot::update()
{
	for (auto ite : parties_m){
		ite->update();
	}
}

void MemoryFromRoot::draw()const
{
	drawMemory();
	drawArrow();
}

void MemoryFromRoot::alloc()
{
	int address = memory_m.alloc();
	if (address != 0) {
		memory_m.access(address).setCenter(positionList_m.getRandomPos());
		intentLink(address);
	}
}

void MemoryFromRoot::intentLink(int allocAddress)
{
	int from = -1;	// 出発地
	int to = -1;	// 目的地
	from = 0;
	to = allocAddress;
	memory_m.link(from, to);
}

void MemoryFromRoot::drawMemory()const
{
	static const Font font;
	drawRoot(contentName_m);
	

	//オブジェクトを描く
	auto drawCircle = [this](int address) {
		if (!memory_m.hasExpired(address)) {
			Circle c = Circle(memory_m.access(address).getCenter(), MEMORY_RADIUS);
			c.draw(Color(Palette::Red, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
			parties_m[address - 1]->draw(c.center);
		}
	};
	for (int i(1); i < memory_m.size(); ++i) {
		drawCircle(i);
	}
}

void MemoryFromRoot::drawArrow()const
{
	static const Font font;

	//ルートからの参照を描く
	auto rm = memory_m.getRelation();
	for (int j(1); j < memory_m.size(); ++j) {
		Line(memory_m.root().getCenter(), memory_m.access(j).getCenter()).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
	}
}

void MemoryFromRoot::drawRoot(String content)const
{
	const Font font;
	font.drawCenter(content, Circle(memory_m.root().getCenter(), ROOT_RADIUS).draw(Palette::Aqua).center);
}