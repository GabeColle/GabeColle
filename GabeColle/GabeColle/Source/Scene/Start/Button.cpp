#include "Button.h"

using namespace start;

Button::Button(Rect const &rect, String text, String soundName)
{
	if (!FontAsset::IsRegistered(L"ButtonFont")) {
		FontAsset::Register(L"ButtonFont", 32);
	}
	if (!SoundAsset::IsRegistered(soundName)) {
		SoundAsset::Register(soundName, soundName);
	}

	rect_m = RoundRect(rect, 8);
	text_m = text;
	soundName_m = soundName;
}


Button::~Button()
{}


void Button::update()
{
	changeState();

	switch (state_m) {
	case start::Button::PRESSED:
		break;
	case start::Button::OVER:
		break;
	case start::Button::LEFT:
		break;
	case start::Button::CLICKED:
		if (frame_m == 2) {
			SoundAsset(soundName_m).play();
		}
	default:
		break;
	}

}

void Button::changeState()
{
	if ((state_m == CLICKED && frame_m > 30) || state_m != CLICKED) {
		if (rect_m.leftPressed && state_m != PRESSED) {
			state_m = PRESSED;
			frame_m = 0;
		}
		else if (state_m == PRESSED && rect_m.leftReleased) {
			state_m = CLICKED;
			frame_m = 0;
		}
		else if (rect_m.mouseOver && !rect_m.leftPressed && state_m != OVER) {
			state_m = OVER;
			frame_m = 0;
		}
		else if (!rect_m.mouseOver && state_m != LEFT) {
			state_m = LEFT;
			frame_m = 0;
		}
	}
	++frame_m;
}

void Button::draw()
{
	switch (state_m) {
	case start::Button::PRESSED:
		drawRessed(rect_m, text_m, frame_m);
		break;
	case start::Button::OVER:
		drawOver(rect_m, text_m, frame_m);
		break;
	case start::Button::LEFT:
		drawLeft(rect_m, text_m, frame_m);
		break;
	case start::Button::CLICKED:
		drawClicked(rect_m, text_m, frame_m);
	default:
		break;
	}
}

void Button::drawRessed(RoundRect rect, String const &text, int frame)const
{
	rect.moveBy(0.0, 2.0).draw(HSV(120, 0.5, 0.8));
	FontAsset(FONT_ASSET_NAME).drawCenter(text_m, rect.rect.center);
}

void Button::drawOver(RoundRect rect, String const &text, int frame)const
{
	double const interval = 45.0;
	double t = static_cast<double>(frame_m % static_cast<int>(interval));

	rect.draw(HSV(120, 0.5, 0.9));
	rect.setSize(t * 2 + rect.w, t / 2 + rect.h)
		.setCenter(rect.rect.center)
		.drawFrame(0.0, 2.0, HSV(120, 0.5 - 0.5 * t / interval, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text_m, rect.rect.center);
}

void Button::drawLeft(RoundRect rect, String const &text, int frame)const
{
	rect.draw(HSV(120, 0.5, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text_m, rect.rect.center);
}

void Button::drawClicked(RoundRect rect, String const &text, int frame)const
{
	double t = static_cast<double>(frame);
	static Point clickPoint;
	if (frame <= 1) {
		clickPoint = Mouse::Pos();
	}
	rect.draw(HSV(120, 0.5, 1.0));
	FontAsset(FONT_ASSET_NAME).drawCenter(text_m, rect.rect.center);
	Circle(clickPoint, t * 5.0).drawFrame(0.0, 2.0,
		HSV(0.0, 0.8 , 1.0).toColor().setAlpha(255 - static_cast<int>(t /31.0 * 255.0)));

}


bool Button::isClicked()const
{
	return state_m == CLICKED && frame_m == 30;
}

String const Button::FONT_ASSET_NAME(L"ButtonFont");
