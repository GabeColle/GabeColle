#pragma once

#include<siv3D.hpp>

class LinkArrow
{
	Color color_m;
	Vec2 to_m;
	Vec2 from_m;
	enum Shape
	{
		CIRCLE,
		LINE,
	};
	Shape shape_m;
	bool isVisible_m = false;
public:
	void draw()const;
	bool isVisible()const;
	void show(Vec2 const &from, Vec2 const &to);
	void hide();
	LinkArrow();
	~LinkArrow() = default;
};

