
#include "Button.h"
#include"ButtonOverEffect.h"

using namespace clickable;

Button::Button(Rect const &rect, String text, String soundName)
	:Button(rect, text, 120, soundName)
{}

Button::Button(Rect const &rect, String text, int h, String soundName)
	: ClickableBase(RoundRect(rect, 8), text)
{
	if (!FontAsset::IsRegistered(FONT_ASSET_NAME)) {
		FontAsset::Register(FONT_ASSET_NAME, 32);
	}
	if (!SoundAsset::IsRegistered(soundName)) {
		SoundAsset::Register(soundName, soundName);
	}

	soundName_m = soundName;
	color_m = HSV(h, 0.0, 0.0);
}

Button::~Button()
{}

void Button::update(Effect &effect)
{
	ClickableBase<RoundRect>::update();

	switch (state_m) {
	case clickable::Button::PRESSED:
		break;
	case clickable::Button::OVER:
		if (frame_m%20 == 0) {
			effect.add<ButtonOverEffect>(
				color_m, shape_m);
		}
		break;
	case clickable::Button::LEFT:
		break;
	case clickable::Button::CLICKED:
		if (frame_m == 2) {
			SoundAsset(soundName_m).play();
		}
	default:
		break;
	}

}

void Button::drawPressed(RoundRect shape, String const &text, int frame)const
{
	shape.moveBy(0.0, 2.0).draw(color_m + HSV(0, 0.5, 0.8));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
}

void Button::drawOver(RoundRect shape, String const &text, int frame)const
{
	shape.draw(color_m + HSV(0, 0.5, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
}

void Button::drawLeft(RoundRect shape, String const &text, int frame)const
{
	shape.draw(color_m + HSV(0, 0.5, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
}

void Button::drawClicked(RoundRect shape, String const &text, int frame)const
{
	double t = static_cast<double>(frame);
	static Point clickPoint;
	if (frame <= 1) {
		clickPoint = Mouse::Pos();
	}
	shape.draw(color_m + HSV(0, 0.5, 1.0));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
	Circle(clickPoint, t * 5.0).drawFrame(0.0, 2.0,
		(color_m + HSV(180, 0.8, 1.0)).toColor().setAlpha(255 - static_cast<int>(t / 31.0 * 255.0)));

}

String const Button::FONT_ASSET_NAME(L"ButtonFont");
