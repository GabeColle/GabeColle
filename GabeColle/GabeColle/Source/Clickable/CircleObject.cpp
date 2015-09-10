#include "CircleObject.h"
#include"CircleObjectTextEffect.h"

using namespace clickable;

CircleObject::CircleObject()
{
	if (!FontAsset::IsRegistered(FONT_ASSET_NAME)) {
		FontAsset::Register(FONT_ASSET_NAME, 24);
	}
	clickedInterval_m = 1;
}

void CircleObject::initialize(int address, Effect &effect)
{
	if (address == 0) {
		shape_m = Circle(Window::Center(), 50.0);
		text_m = L"ROOT";
	}
	else {
		shape_m = Circle(RandomVec2({ 0, 1280 }, { 0, 720 }), 30.0);
		text_m = ToString(address);
	}
	show();
	
	effect.add<CircleObjectTextEffect>(
		shape_m.center,
		FontSharedText(
			FONT_ASSET_NAME, L"NEW", shape_m.center.movedBy(0,-45), Palette::Red));
}

void CircleObject::finalize(Effect &effect)
{
	frame_m = clickedInterval_m + 1;
	hide();
	effect.add<CircleObjectTextEffect>(
		shape_m.center,
		FontSharedText(
			FONT_ASSET_NAME, L"DELETE", shape_m.center.movedBy(0,45), Palette::Blue));

	changeState();
}

Vec2 CircleObject::center()const
{
	return shape_m.center;
}

void CircleObject::update()
{
	if (text_m != L"ROOT") {
		ClickableBase<Circle>::update();
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

String const CircleObject::FONT_ASSET_NAME(L"CircleObjectFont");
