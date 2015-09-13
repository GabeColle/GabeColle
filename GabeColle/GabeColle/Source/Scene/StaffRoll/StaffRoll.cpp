#include "StaffRoll.h"

StaffRoll::StaffRoll()
{
}

void StaffRoll::init()
{
	changeFrame_m = 100;
	contentNumber_m = 0;
	contents[0] = new StaffRollContent(4, L"Programmer");
	contents[1] = new StaffRollContent(4, L"BGM");
	contents[2] = new StaffRollContent(4, L"Idea");
	contents[3] = new StaffRollContent(4, L"Graphic");
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