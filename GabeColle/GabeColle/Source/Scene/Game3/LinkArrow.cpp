#include "LinkArrow.h"

LinkArrow::LinkArrow()
{
	color_m = RandomColorH(0.8, 0.9).setAlpha(167);
}

void LinkArrow::draw()const
{
	if (isVisible()) {
		if (shape_m == LINE) {
			Line(from_m, to_m).drawArrow(4, { 20, 50 }, color_m);
		}
		else {
			auto const &center = from_m;
			Circle(center.movedBy(40.0, -40.0), 40.0)
				.drawArc(-Math::Pi / 2.0, 1.5 * Math::Pi, 2.0, 2.0, color_m);
			Line(center.movedBy(0.0, -40.0), center).drawArrow(4, { 20, 50 }, color_m);
			Line(center.movedBy(40.0, 0.0), center).draw(4, color_m);
		}
	}
}

void LinkArrow::show(Vec2 const &from, Vec2 const &to)
{
	Visibility::show();
	from_m = from;
	to_m = to;
	shape_m = from == to ? CIRCLE : LINE;
}
