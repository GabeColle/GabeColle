#pragma once

#include<Siv3D.hpp>

namespace clickable{

class ButtonClickedEffect :
	public IEffect
{
public:
	HSV const color_m;
	Vec2 const center_m;
public:
	ButtonClickedEffect(HSV const &color, Vec2 const &center);

	bool update(double t)override;
};

}