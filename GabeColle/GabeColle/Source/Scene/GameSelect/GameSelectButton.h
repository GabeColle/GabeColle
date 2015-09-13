#pragma once
#include"../../Clickable/Button.h"

class GameSelectButton
	: public clickable::Button
{
public:
	GameSelectButton(Rect const &rect, String text, String soundName)
		: Button(rect,  text,  soundName)
	{};
	GameSelectButton(Rect const &rect, String text, int h, String soundName)
		: Button(rect, text, h, soundName)
	{};
	~GameSelectButton(){};
	

	bool isMouceOver()const
	{
		return shape_m.mouseOver;
	}
	
	void drawShadow()const
	{
		shape_m.drawShadow({ 0, 3 }, 3);
	}
private:
	
};