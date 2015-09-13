#pragma once
#pragma warning(disable:4100)

#include<Siv3D.hpp>

#include"Clickable.h"
#include"../Utility/Visibility.h"

namespace clickable {

template<class Shape>
class ClickableBase :
	public clickable::Clickable, public Visibility
{
protected:
	enum State
	{
		PRESSED,
		OVER,
		LEFT,
		CLICKED,
	}; 
	
	int frame_m = 0;
	int clickedInterval_m = 20;
	State state_m = LEFT;
	Shape shape_m;
	String text_m;

	virtual void changeState()
	{
		if ((state_m == CLICKED && frame_m > clickedInterval_m) || state_m != CLICKED) {
			if (shape_m.leftPressed && state_m != PRESSED) {
				state_m = PRESSED;
				frame_m = 0;
			}
			else if (state_m == PRESSED && shape_m.leftReleased) {
				state_m = CLICKED;
				frame_m = 0;
			}
			else if (shape_m.mouseOver && !shape_m.leftPressed && state_m != OVER) {
				state_m = OVER;
				frame_m = 0;
			}
			else if (!shape_m.mouseOver && state_m != LEFT) {
				state_m = LEFT;
				frame_m = 0;
			}
		}
		++frame_m;
	}
	virtual void drawPressed(Shape shape, String const &text, int frame)const {};
	virtual void drawOver(Shape shape, String const &text, int frame)const {};
	virtual void drawLeft(Shape shape, String const &text, int frame)const {};
	virtual void drawClicked(Shape shape, String const &text, int frame)const {};
public:
	ClickableBase() = default;
	ClickableBase(Shape const &shape, String const &text)
	{
		shape_m = shape;
		text_m = text;
	}
	virtual ~ClickableBase() = default;

	virtual void update()
	{
		changeState();
	}
	virtual void draw()const
	{
		if (isVisible()) {
			switch (state_m) {
			case PRESSED:
				drawPressed(shape_m, text_m, frame_m);
				break;
			case OVER:
				drawOver(shape_m, text_m, frame_m);
				break;
			case LEFT:
				drawLeft(shape_m, text_m, frame_m);
				break;
			case CLICKED:
				drawClicked(shape_m, text_m, frame_m);
			default:
				break;
			}
		}
	}
	virtual bool isClicked()const
	{
		return state_m == CLICKED && frame_m == clickedInterval_m && isVisible();
	}
};

}
