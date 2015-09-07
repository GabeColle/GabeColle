#include "CircleObject.h"

using namespace clickable;

CircleObject::CircleObject()
{
	if (!FontAsset::IsRegistered(L"CircleFont")) {
		FontAsset::Register(L"CircleFont", 32);
	}
}

void CircleObject::alloc(int address)
{
	shape_m = address == 0 ? Circle(Window::Center(), 30.0) :
		Circle(RandomVec2(1280, 720), 20.0);
	text_m = ToString(address);
	objectState_m = ALLOCED;
	objectFrame_m = 0;
}

void CircleObject::free()
{
	objectState_m = FREED;
	objectFrame_m = 0;
}

void CircleObject::changeOobjectState()
{
	++objectFrame_m;
	if (objectState_m == EXPAIRED) {}
	else if (objectState_m == ALLOCED && objectFrame_m > 30) {
		objectState_m = EXISTS;
		objectFrame_m = 0;
	}
	else if(objectState_m == EXISTS){}
	else if (objectState_m == FREED && objectFrame_m > 30) {
		objectState_m = EXPAIRED;
		objectFrame_m = 0;
	}
}

void CircleObject::update()
{
	ClickableBase<Circle>::update();
	changeOobjectState();
}

void CircleObject::draw()const
{
	switch (objectState_m) {
	case CircleObject::ALLOCED:
		ClickableBase<Circle>::draw();
		FontAsset(FONT_ASSET_NAME).drawCenter(
			L"NEW", shape_m.center.movedBy(0.0, 25.0), HSV(240, 0.5, 0.9));
		break;
	case CircleObject::FREED:
		ClickableBase<Circle>::draw();
		FontAsset(FONT_ASSET_NAME).drawCenter(
			L"DELETE", shape_m.center.movedBy(0.0, 25.0), HSV(300, 0.5, 0.9));
		break;
	case CircleObject::EXISTS:
		ClickableBase<Circle>::draw();
		break;
	case CircleObject::EXPAIRED:
		break;
	default:
		break;
	}

}

void CircleObject::drawPressed(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.5, 1.0));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

void CircleObject::drawOver(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.5, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

void CircleObject::drawLeft(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.5, 0.8));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

void CircleObject::drawClicked(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.5, 0.7));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

String const CircleObject::FONT_ASSET_NAME(L"ButtonFont");
