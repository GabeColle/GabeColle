
#include "Button.h"
#include"ButtonOverEffect.h"
#include"ButtonClickedEffect.h"

using namespace clickable;

String const Button::FONT_ASSET_NAME(L"ButtonFont");

std::unique_ptr<Effect> Button::effect_m = nullptr;

void Button::drawEffect()
{
	if (effect_m != nullptr) {
		effect_m->update();
	}
}

Button::Button(Rect const &rect, String text, String soundName)
	:Button(rect, text, 120, soundName)
{}

Button::Button(Rect const &rect, String text, int h, String soundName)
	: ClickableBase(RoundRect(rect, 8), text)
{
	if (effect_m == nullptr) {
		effect_m = std::make_unique<Effect>();
	}
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

void Button::update()
{
	ClickableBase<RoundRect>::update();

	switch (state_m) {
	case clickable::Button::PRESSED:
		break;
	case clickable::Button::OVER:
		if (frame_m%30 == 1) {
			effect_m->add<ButtonOverEffect>(color_m, shape_m);
		}
		break;
	case clickable::Button::LEFT:
		break;
	case clickable::Button::CLICKED:
		if (frame_m == 1) {
			SoundAsset(soundName_m).play();
			effect_m->add<ButtonClickedEffect>(color_m, Mouse::Pos());
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
	shape.draw(color_m + HSV(0, 0.5, 1.0));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center);
}
