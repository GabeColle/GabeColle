#include "CircleObject.h"
#include"CircleObjectTextEffect.h"

using namespace clickable;

String const CircleObject::fontAsset_m(L"CircleObjectFont");
String const CircleObject::newSound_m = L"Asset/SoundEffect/New.ogg";
String const CircleObject::deleteSound_m = L"Asset/SoundEffect/Delete.ogg";

CircleObject::CircleObject()
{
	if (!FontAsset::IsRegistered(fontAsset_m)) {
		FontAsset::Register(fontAsset_m, 24);
	}
	if (!SoundAsset::IsRegistered(newSound_m)) {
		SoundAsset::Register(newSound_m, newSound_m);
	}
	if (!SoundAsset::IsRegistered(deleteSound_m)) {
		SoundAsset::Register(deleteSound_m, deleteSound_m);
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
	SoundAsset(newSound_m).playMulti();
	effect.add<CircleObjectTextEffect>(
		shape_m.center,
		FontSharedText(
			fontAsset_m, L"NEW", shape_m.center.movedBy(0,-45), Palette::Red));
}

void CircleObject::finalize(Effect &effect)
{
	frame_m = clickedInterval_m + 1;
	hide();
	SoundAsset(deleteSound_m).playMulti();
	effect.add<CircleObjectTextEffect>(
		shape_m.center,
		FontSharedText(
			fontAsset_m, L"DELETE", shape_m.center.movedBy(0,45), Palette::Blue));

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
	FontAsset(fontAsset_m).drawCenter(text, shape.center);
}

void CircleObject::drawOver(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.7, 0.9)).drawFrame(1.0, 0.0, HSV(0, 1.0, 0.9));
	FontAsset(fontAsset_m).drawCenter(text, shape.center);
}

void CircleObject::drawLeft(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.7, 0.8)).drawFrame(1.0, 0.0, HSV(0, 1.0, 0.8));
	FontAsset(fontAsset_m).drawCenter(text, shape.center);
}

void CircleObject::drawClicked(Circle shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.7, 0.5)).drawFrame(1.0, 0.0, HSV(0, 1.0, 0.5));
	FontAsset(fontAsset_m).drawCenter(text, shape.center);
}

bool CircleObject::isClicked()const
{
	return shape_m.leftClicked;
}
