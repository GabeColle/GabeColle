#pragma once

#include<siv3D.hpp>
#include"../../Utility/Visibility.h"

class LinkArrow : public Visibility
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
public:
	void draw()const;
	void show(Vec2 const &from, Vec2 const &to);
	LinkArrow();
	~LinkArrow() = default;
};

