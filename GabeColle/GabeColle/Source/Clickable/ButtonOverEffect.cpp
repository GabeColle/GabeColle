#include "ButtonOverEffect.h"

using namespace clickable;

ButtonOverEffect::ButtonOverEffect(HSV const &color, RoundRect const &rect)
	:color_m(color), rect_m(rect), frame_m(rect)
{}

bool ButtonOverEffect::update(double t)
{
	if (t > 1.0) {
		return false;
	}
	frame_m.setSize(rect_m.w*(1.0 + 1.5*t), rect_m.h*(1.0 + 0.7*t))
		.setCenter(rect_m.rect.center)
		.drawFrame(0.0, 2.0, ColorF(color_m + HSV(0.0, 0.5, 0.9)).setAlpha(1.0 - (t / 2.0)));

	return true;
}
