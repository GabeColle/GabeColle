#include "MemoryWrapper.h"


const double MemoryWrapper::MEMORY_RADIUS = 40.0;
const double MemoryWrapper::ROOT_RADIUS = 50.0;


MemoryWrapper::MemoryWrapper() : memory_m(41), positionList_m()
{
}


void MemoryWrapper::init()
{
	memory_m.root().setCenter(positionList_m.getRootPos());
}

void MemoryWrapper::alloc()
{
	int address = memory_m.alloc();
	if(address != 0) {
		memory_m.access(address).setCenter(positionList_m.getRandomPos());
		randomLink(address);
	}
}

bool MemoryWrapper::free()
{
	bool isFree = false;
	for(int i(1); i < memory_m.size(); ++i) {
		if(!memory_m.hasExpired(i) && Circle(memory_m.access(i).getCenter(), 40.0).mouseOver) {
			positionList_m.restoreRandomPos(memory_m.access(i).getCenter());
			memory_m.free(i);
			isFree = true;
		}
	}
	return isFree;
}

void MemoryWrapper::draw() const
{
	static Font font;

	font(L"Segmentation Fault	: " + ToString(memory_m.error().segmentationFault_m)).draw(10, 0);
	font(L"Out of Memory		: " + ToString(memory_m.error().outOfMemory_m)).draw(10, 30);

	font.drawCenter(L"Root", Circle(memory_m.root().getCenter(), ROOT_RADIUS).draw(Palette::Aqua).center);

	//オブジェクトを描く
	auto drawCircle = [this](int address) {
		if(!memory_m.hasExpired(address)) {
			Circle c = Circle(memory_m.access(address).getCenter(), MEMORY_RADIUS);
			if(c.mouseOver) {
				c.draw(Color(Palette::Pink, 128)).drawFrame(0.0, 3.0, Palette::Red);
			} else {
				c.draw(Color(Palette::Red, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
			}
			font.drawCenter(ToString(address), c.center);
		}
	};
	for(int i(1); i < memory_m.size(); ++i) {
		drawCircle(i);
	}
	
	//ルートからの参照を描く
	auto rm = memory_m.getRelation();
	for(int j(1); j < memory_m.size(); ++j) {
		if(rm.areLinked(0, j)) {
			Line(memory_m.root().getCenter(), memory_m.access(j).getCenter()).drawArrow(4, {20, 50}, Color(Palette::Yellow, 128));
		} else if(rm.areLinked(j, 0)) {
			Line(memory_m.access(j).getCenter(), memory_m.root().getCenter()).drawArrow(4, {20, 50}, Color(Palette::Yellow, 128));
		}
	}

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

//GameData MemoryWrapper::calculateScore()
//{
//	data_m.numOfError = 
//		  memory_m.error().outOfMemory_m
//		+ memory_m.error().segmentationFault_m
//		+ memory_m.error().nullptrAccess_m
//		+ memory_m.error().addressOutOfBounds_m;
//
//	data_m.totalScore = 
//		  data_m.time
//		+ data_m.numOfDeletedObject
//		- data_m.numOfError;
//}


void MemoryWrapper::randomLink(int allocAddress)
{
	int from = -1;	// 出発地
	int to = -1;	// 目的地
	if(RandomBool(0.7)) {
		std::vector<int> numList = getExistAddress();
		std::random_shuffle(numList.begin(), numList.end());
		if(RandomBool(0.5)) {
			from = numList[0];
			to = allocAddress;
		}
		else {
			from = allocAddress;
			to = numList[0];
		}
	}
	if(from != -1 && to != -1) {
		memory_m.link(from, to);
	}
}

std::vector<int> MemoryWrapper::getExistAddress()
{
	std::list<int> numList(0);
	for(int i(0); i < memory_m.size(); ++i) {
		if(!memory_m.hasExpired(i)) {
			numList.push_back(i);
		}
	}
	std::vector<int> numVector(numList.begin(), numList.end());
	return numVector;
}