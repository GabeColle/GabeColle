#include "ButtonClickedEffect.h"

using namespace clickable;

ButtonClickedEffect::ButtonClickedEffect(HSV const &color, Vec2 const &center)
	:color_m(color), center_m(center)
{}

bool ButtonClickedEffect::update(double t)
{
	if (t > 1.0) {
		return false;
	}

	Circle(center_m, t * 200).drawFrame(
		0.0, 2.0, ColorF(color_m + HSV(180, 1.0, 0.9)).setAlpha(1.0 - t));

	return true;
}