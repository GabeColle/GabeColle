#include "BackGroundAnimation.h"

BackGroundAnimation::BackGroundAnimation() : texture_m(L"Asset/Image/resultBG2.png")
{
	if (!texture_m)
	{
		return;	// ƒ[ƒh‚ÉŽ¸”s‚µ‚½‚çI—¹
	}
	BGVelocity_m = 1;
	bg_x_m = 0;
	bg_x2_m = texture_m.size.x;

}

void BackGroundAnimation::update()
{
	bg_x_m = (bg_x_m > -texture_m.size.x) ? bg_x_m - BGVelocity_m : texture_m.width;
	bg_x2_m = (bg_x2_m > -texture_m.size.x) ? bg_x2_m - BGVelocity_m : texture_m.width;
}

void BackGroundAnimation::draw()const
{
	texture_m.draw(bg_x_m, 0);
	texture_m.mirror().draw(bg_x2_m, 0);
}