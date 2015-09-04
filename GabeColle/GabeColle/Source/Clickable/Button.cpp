
#include "Button.h"

using namespace clickable;

Button::Button(Rect const &rect, String text, String soundName)
	:ClickableBase(RoundRect(rect, 8), text)
{
	if (!FontAsset::IsRegistered(L"ButtonFont")) {
		FontAsset::Register(L"ButtonFont", 32);
	}
	if (!SoundAsset::IsRegistered(soundName)) {
		SoundAsset::Register(soundName, soundName);
	}

	soundName_m = soundName;
}


Button::~Button()
{}

void Button::update()
{
	ClickableBase<RoundRect>::update();// changeState();

	switch (state_m) {
	case clickable::Button::PRESSED:
		break;
	case clickable::Button::OVER:
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
	shape.moveBy(0.0, 2.0).draw(HSV(120, 0.5, 0.8));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
}

void Button::drawOver(RoundRect shape, String const &text, int frame)const
{
	double const interval = 45.0;
	double t = static_cast<double>(frame % static_cast<int>(interval));

	shape.draw(HSV(120, 0.5, 0.9));
	shape.setSize(t * 2 + shape.w, t / 2 + shape.h)
		.setCenter(shape.rect.center)
		.drawFrame(0.0, 2.0, HSV(120, 0.5 - 0.5 * t / interval, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
}

void Button::drawLeft(RoundRect shape, String const &text, int frame)const
{
	shape.draw(HSV(120, 0.5, 0.9));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
}

void Button::drawClicked(RoundRect shape, String const &text, int frame)const
{
	double t = static_cast<double>(frame);
	static Point clickPoint;
	if (frame <= 1) {
		clickPoint = Mouse::Pos();
	}
	shape.draw(HSV(120, 0.5, 1.0));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
	Circle(clickPoint, t * 5.0).drawFrame(0.0, 2.0,
		HSV(0.0, 0.8 , 1.0).toColor().setAlpha(255 - static_cast<int>(t /31.0 * 255.0)));

}

String const Button::FONT_ASSET_NAME(L"ButtonFont");
