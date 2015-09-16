#pragma once

#include<Siv3D.hpp>
#include"../Utility/Text.h"

class CircleObjectTextEffect :
	public IEffect
{
	FontSharedText text_m;
	const Vec2 center_m;
public:
	CircleObjectTextEffect(Vec2 center, FontSharedText text)
		: center_m(center), text_m(text)
	{}

	bool update(double t) override
	{
		if (t >= 1.0) {
			return false;
		}
		text_m.color(ColorF(text_m.color()).setAlpha(1.0 - t));
		text_m.center(text_m.center().movedBy(0, -1));
		text_m.draw();

		return true;
	}
	~CircleObjectTextEffect();
};

