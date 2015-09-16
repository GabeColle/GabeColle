#pragma once
#include<Siv3D.hpp>

namespace clickable{

class ButtonOverEffect :
	public IEffect
{
	HSV const color_m;
	RoundRect const rect_m;
	RoundRect frame_m;
public:
	ButtonOverEffect(HSV const &color, RoundRect const &rect);
		
	bool update(double t)override;
};

}