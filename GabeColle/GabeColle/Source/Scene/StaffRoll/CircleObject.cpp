#include "CircleObject.h"

using namespace staffroll;

Vec2 CircleObject::getCenter() const
{
	return Vec2(x_m, y_m);
}

void CircleObject::setCenter(Vec2 v)
{
	x_m = v.x;
	y_m = v.y;
}

void CircleObject::setX(double x)
{
	x_m = x;
}

void CircleObject::setY(double y)
{
	y_m = y;
}