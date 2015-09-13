#include "StaffRollContent.h"

const int StaffRollContent::INIT_OBJECTS = 40;

StaffRollContent::StaffRollContent(int numOfObjectFromRoot, String contentName)
{
	Array<String> parties = { L"HataG", L"Jumpaku", L"Namba", L"Uhhyoi"};
	memoryR_m = new staffroll::MemoryFromRoot(numOfObjectFromRoot, contentName, parties);
	init();
}

void StaffRollContent::init()
{
	for (int i = 0; i < INIT_OBJECTS; ++i){
		memory_m.alloc();
		memoryR_m->alloc();
	}
}

void StaffRollContent::update()
{
	// メモリの開放
	if (!memory_m.getExistAddress().empty()){
		memory_m.free(memory_m.getExistAddress().at(Random(0, (int)memory_m.getExistAddress().size() - 1)));
	}
	memory_m.update();
	memoryR_m->update();
}

void StaffRollContent::draw()const
{
	memory_m.draw();
	memoryR_m->draw();
}