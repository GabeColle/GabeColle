#include "CircleObject.h"

using namespace clickable;

CircleObject::CircleObject()
{
	if (!FontAsset::IsRegistered(FONT_ASSET_NAME)) {
		FontAsset::Register(FONT_ASSET_NAME, 24);
	}
}

void CircleObject::initialize(int address)
{
	if (address == 0) {
		shape_m = Circle(Window::Center(), 50.0);
		text_m = L"ROOT";
		objectState_m = EXISTS;
	}
	else {
		shape_m = Circle(RandomVec2({ 0, 1280 }, { 0, 720 }), 30.0);
		text_m = ToString(address);
		objectState_m = ALLOCED;
	}
	objectFrame_m = 0;
	show();

	clickedInterval_m = 10;
}

void CircleObject::finalize()
{
	frame_m = clickedInterval_m + 1;
	hide();
	changeState();
}

Vec2 CircleObject::center()const
{
	return shape_m.center;
}
void CircleObject::changeObjectState()
{
	++objectFrame_m;
	if (objectState_m == EXPAIRED) {}
	else if (objectState_m == ALLOCED && objectFrame_m > clickedInterval_m) {
		objectState_m = EXISTS;
		objectFrame_m = 0;
	}
	else if(objectState_m == EXISTS && state_m == CLICKED){
		objectState_m = FREED;
		objectFrame_m = 0;
	}
	else if (objectState_m == FREED && objectFrame_m > clickedInterval_m) {
		objectState_m = EXPAIRED;
		objectFrame_m = 0;
	}
}

void CircleObject::update()
{
	if (text_m != L"ROOT") {
		ClickableBase<Circle>::update();
		changeObjectState();
	}
}

void CircleObject::draw()const
{
	static double const A = 1.0;
	static double const B = 0.3;
	double x = 
		static_cast<double>(objectFrame_m) / static_cast<double>(clickedInterval_m);
	double v = (std::max)(0.0, (std::min)(1.0, (std::min)(A*x + B, -1.0 * A *x + A + B)));
	
	switch (objectState_m) {
	case CircleObject::ALLOCED:
		ClickableBase<Circle>::draw();
		FontAsset(FONT_ASSET_NAME).drawCenter(
			L"NEW", shape_m.center.movedBy(0.0, -40.0), HSV(240, 0.7, v));
		break;
	case CircleObject::FREED:
		ClickableBase<Circle>::draw();
		FontAsset(FONT_ASSET_NAME).drawCenter(
			L"DELETE", shape_m.center.movedBy(0.0, 45.0), HSV(300, 0.7, v));
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
	shape.draw(HSV(0, 0.7, 1.0)).drawFrame(1.0, 0.0, HSV(0, 1.0, 1.0));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

void CircleObject::drawOver(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.7, 0.9)).drawFrame(1.0, 0.0, HSV(0, 1.0, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

void CircleObject::drawLeft(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.7, 0.8)).drawFrame(1.0, 0.0, HSV(0, 1.0, 0.8));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

void CircleObject::drawClicked(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.7, 0.5)).drawFrame(1.0, 0.0, HSV(0, 1.0, 0.5));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.center);
}

bool CircleObject::isFreed()const
{
	return objectState_m == FREED;
}

String const CircleObject::FONT_ASSET_NAME(L"CircleObjectFont");
