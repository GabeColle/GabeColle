#include "OutOfEffect.h"


OutOfEffect::OutOfEffect(const Font& font) : font_m(font)
{
}


bool OutOfEffect::update(double t)
{
	if(t > 1.0) { return false; }
	const double alpha = 255 * Cos((t / 2.0) * Pi);
	const double rectAlpha = 100 * Cos((t / 2.0) * Pi);
	font_m(L"Segmentation Fault î≠ê∂íÜÅIÅI").drawCenter(Rect(1280, 50).setCenter(Window::Center().x, 25).draw(Color(Palette::Blue, static_cast<uint32>(rectAlpha))).center, Color(Palette::White, static_cast<uint32>(alpha)));
	return true;
}