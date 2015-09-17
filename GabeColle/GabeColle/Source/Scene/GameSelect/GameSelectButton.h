#pragma once
#include"../../Clickable/Button.h"

class GameSelectButton
	: public clickable::Button
{
	void drawShadow()const
	{
		shape_m.drawShadow({0, 3}, 3);
	}
public:
	GameSelectButton(Rect const &rect, String text, String soundName)
		: Button(rect,  text,  soundName)
	{
		show();
	}
	GameSelectButton(Rect const &rect, String text, int h, String soundName)
		: Button(rect, text, h, soundName)
	{
		show();
	}
	~GameSelectButton(){}
	

	bool isMouceOver()const
	{
		return shape_m.mouseOver;
	}
	
	void draw()const override
	{
		drawShadow();
		Button::draw();
	}
private:
	
};