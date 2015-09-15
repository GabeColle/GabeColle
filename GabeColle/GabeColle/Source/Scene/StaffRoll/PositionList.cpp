#include "PositionList.h"

using namespace staffroll;
const int PositionList::MEMORY_RADIUS = 100;
const int PositionList::POSITION_NUM_X = 1280 / (MEMORY_RADIUS*2);
const int PositionList::POSITION_NUM_Y = 720 / (MEMORY_RADIUS*2);
//const int PositionList::POSITION_MARGIN_X = 24;
//const int PositionList::POSITION_MARGIN_Y = 40;




PositionList::PositionList() : posList_m(0)
{
	initPosList();
}


Vec2 PositionList::getRootPos()
{
	return rootPos_m;
}

Vec2 PositionList::getRandomPos()
{
	/*int randomIndex = Random(posList_m.size() - 1);
	auto itr = posList_m.begin();
	for(int i(0); i < randomIndex; ++i, ++itr);
	Vec2 pos = *itr;
	posList_m.erase(itr);
	return pos;
	*/
	return posList_m.at(Random(0, (int)(posList_m.size() - 1)));
		
}

void PositionList::restoreRandomPos(Vec2 pos)
{
	posList_m.push_back(pos);
}


void PositionList::initPosList()
{
	/*for(int i(0); i < POSITION_NUM_X; ++i) {
		for(int j(0); j < POSITION_NUM_Y; ++j) {
			// root‚ÌˆÊ’u‚ðÝ’è
			if(i == POSITION_NUM_X / 2 && j == POSITION_NUM_Y / 2) {
				rootPos_m = {Window::Center().x, Window::Center().y + 32};
			}
			// rootˆÈŠO‚ÌˆÊ’u‚ðÝ’è
			else {
				if(i % 2 == 0) {
					posList_m.push_back(Vec2(40 + (i + 1) * 2 * 40 + i * POSITION_MARGIN_X, 40 + (j + 1) * 2 * 40 + j * POSITION_MARGIN_Y - 32));
				} else {
					posList_m.push_back(Vec2(40 + (i + 1) * 2 * 40 + i * POSITION_MARGIN_X, 40 + (j + 1) * 2 * 40 + j * POSITION_MARGIN_Y + 32));
				}
			}
		}
	}*/
	rootPos_m = { Window::Center().x, Window::Center().y + 32 };
	for (int i = 0; i < POSITION_NUM_X; ++i){
		for (int j = 0; j < POSITION_NUM_Y; ++j){
			posList_m.push_back(Vec2(MEMORY_RADIUS + i*MEMORY_RADIUS * 2, MEMORY_RADIUS + j*MEMORY_RADIUS * 2));
		}
	}
}