#include "BackGroundAnimation.h"

BackGroundAnimation::BackGroundAnimation() : BGM_m(L"Asset/BGM/bgm_maoudamashii_cyber08.mp3"), texture_m(L"Asset/Image/resultBG2.png")
{
	if (!BGM_m || !texture_m)
	{
		return;	// ÉçÅ[ÉhÇ…é∏îsÇµÇΩÇÁèIóπ
	}
	BGVelocity_m = 1;
	bg_x_m = 0;
	bg_x2_m = texture_m.size.x;
	//tree[0] = new Array<ExpandCircleEffect>(1, *(new ExpandCircleEffect(Circle(Window::Center(), 60), 30, 0, Palette::Aqua)));
	//tree[1] = new Array<ExpandCircleEffect>();
	//tree[2] = new Array<ExpandCircleEffect>();
}

void BackGroundAnimation::update()
{
	bg_x_m = (bg_x_m > -texture_m.size.x) ? bg_x_m - BGVelocity_m : texture_m.width;
	bg_x2_m = (bg_x2_m > -texture_m.size.x) ? bg_x2_m - BGVelocity_m : texture_m.width;
	
	/*if (BG_X <= -texture.size.x){
		BG_X = texture.width;
	}
	if (BG_X2 <= -texture.size.x){
		BG_X2 = texture.width;
	}*/
}

void BackGroundAnimation::draw()const
{
	BGM_m.play();
	texture_m.draw(bg_x_m, 0);
	texture_m.mirror().draw(bg_x2_m, 0);
}