#include "Button.h"

Button::Button(String str , int xPos, int yPos, int width , int height,int fontSize) :font_m(fontSize){
	setColor();
	str_m = str;
	xPos_m = xPos;
	yPos_m = yPos;
	width_m = width;
	height_m = height;
	setRect();
}

Button::Button(String str , Vec2 pos , Vec2 size , int fontSize) :font_m(fontSize){
	setColor();
	str_m = str;
	xPos_m = (int)pos.x;
	yPos_m = (int)pos.y;
	width_m = (int)size.x;
	height_m = (int)size.y;
	setRect();
}

Button::Button(int fontSize,String str, int xPos, int yPos ) :font_m(fontSize){
	setColor();
	str_m = str;
	xPos_m = xPos;
	yPos_m = yPos;
	setRectByFont();
}

Button::Button(int fontSize,String str, Vec2 pos ) :font_m(fontSize){
	setColor();
	str_m = str;
	xPos_m = (int)pos.x;
	yPos_m = (int)pos.y;
	setRectByFont();
}

Button::~Button()
{
}

bool Button::leftClicked(){
	return rect_m.leftClicked;
}

void Button::draw(){
	if (!rect_m.mouseOver){
		rect_m.draw(buttonColor_m);
		font_m(str_m).drawCenter({ xPos_m, yPos_m }, textColor_m);
	}
	else{
		rect_m.draw(mouseoverButtonColor_m);
		font_m(str_m).drawCenter({ xPos_m, yPos_m }, mouseoverTextColor_m);
	}
}

void Button::setColor(Color buttonColor , Color mouseoverButtonColor, Color textColor, Color mouseoverTextColor){

	buttonColor_m = buttonColor;
	mouseoverButtonColor_m = mouseoverButtonColor;
	textColor_m = textColor;
	mouseoverTextColor_m = mouseoverTextColor;
}

void Button::setRectByFont(){
	rect_m = font_m.region(str_m);
	rect_m.setCenter(xPos_m, yPos_m);
}

void Button::setRect(){
	rect_m = Rect(width_m, height_m);
	rect_m.setCenter(xPos_m, yPos_m);
}