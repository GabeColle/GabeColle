#include "FadeOutEffect.h"


FadeOutEffect::FadeOutEffect(Font font, String str, Vec2 pos) : font_m(font), str_m(str), pos_m(pos)
{
}


bool FadeOutEffect::update(double t)
{
	if(t > 0.5) { return false; }
	const double alpha = 255 * Cos(t * Pi);
	font_m(str_m).drawCenter({pos_m.x, pos_m.y - 80}, Color(Palette::Aqua, alpha));
	return true;
}