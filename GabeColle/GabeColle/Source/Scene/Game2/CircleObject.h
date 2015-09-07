#pragma once
#include "../../GC\Object.h"
#include <Siv3D.hpp>

namespace game2{

class CircleObject : public gc::Object
{
	double x_m;
	double y_m;
public:
	Vec2 center()const;
	void center(Vec2 v);
	void x(double x);
	void y(double y);
};

}