#include "StaffRoll.h"

StaffRoll::StaffRoll()
{
}

void StaffRoll::init()
{
	
	changeFrame_m = 150;
	contentNumber_m = 0;
	contents[0] = new StaffRollContent(4, L"Programmer", { L"HataG", L"Jumpaku", L"Namba", L"Uhhyoi" });
	contents[1] = new StaffRollContent(3, L"BGM", { L"誰?", L"誰?", L"誰?" });
	contents[2] = new StaffRollContent(1, L"Idea", { L"Jumpaku" });
	contents[3] = new StaffRollContent(3, L"Graphic", { L"誰?", L"誰?", L"誰?" });
}

void StaffRoll::update()
{
	if (changeFrame_m == 0){
		contentNumber_m = (contentNumber_m + 1)%4;
		changeFrame_m = 160;
	}
	else{
		changeFrame_m--;
	}
	contents[contentNumber_m]->update();
}

void StaffRoll::draw()const
{
	contents[contentNumber_m]->draw();
}