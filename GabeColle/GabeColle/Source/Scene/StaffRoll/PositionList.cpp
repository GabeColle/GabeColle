#include "PositionList.h"

using namespace staffroll;
const int PositionList::MEMORY_RADIUS = 90;
const int PositionList::ROOT_RADIUS = 70;
const int PositionList::POSITION_NUM_X = 1280 / (MEMORY_RADIUS*2);
const int PositionList::POSITION_NUM_Y = 720 / (MEMORY_RADIUS*2);

PositionList::PositionList() : posList_m(0)
{
	initPosList();
}


Vec2 PositionList::getRootPos()
{
	return rootPos_m;
}

Vec2 PositionList::getRandomPos(String measuredString)
{
	static const Font font;
	int ejectionPos = Random(0, (int)(posList_m.size() - 1));
	Vec2 randomPosition = posList_m.at(ejectionPos);
	Rect area = font(measuredString).region((int)randomPosition.x,(int)randomPosition.y);
	if (area.x < 0){
		randomPosition = randomPosition.movedBy(-area.x, 0);
	}
	else if (Window::Width() - area.x < 0){
		randomPosition = randomPosition.movedBy(Window::Width()-(area.x+area.w), 0);
	}
	posList_m.erase(posList_m.begin() + ejectionPos);
	return randomPosition;
}

void PositionList::restoreRandomPos(Vec2 pos)
{
	posList_m.push_back(pos);
}


void PositionList::initPosList()
{
	rootPos_m = { Window::Center().x, Window::Center().y + 32 };
	for (int i = 0; i < POSITION_NUM_X; ++i){
		for (int j = 0; j < POSITION_NUM_Y; ++j){
			int x = MEMORY_RADIUS + i*MEMORY_RADIUS * 2;
			int y = MEMORY_RADIUS + j*MEMORY_RADIUS * 2;
			if (Abs(x - rootPos_m.x) > ROOT_RADIUS + MEMORY_RADIUS && Abs(y - rootPos_m.y) > ROOT_RADIUS + MEMORY_RADIUS){
				posList_m.push_back(Vec2(x,y));
			}
		}
	}
}