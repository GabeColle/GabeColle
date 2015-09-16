#include "TwitterButton.h"

TwitterButton::TwitterButton(Rect const &rect, String text, String soundName) : Button(rect, text, soundName)
{

}

void TwitterButton::update()
{
	Button::update();

}

void TwitterButton::drawPressed(RoundRect shape, String const &text, int frame)const
{
	shape.moveBy(0.0, 2.0).draw(HSV(0, 1.0, 0.75));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center, Palette::Black);
}

void TwitterButton::drawOver(RoundRect shape, String const &text, int frame)const
{
	drawLeft(shape, text, frame);
}

void TwitterButton::drawLeft(RoundRect shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 1.0, 0.85));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center, Palette::Black);
}

void TwitterButton::drawClicked(RoundRect shape, String const &text, int frame)const
{
	double t = static_cast<double>(frame);
	static Point clickPoint;
	if (frame <= 1) {
		clickPoint = Mouse::Pos();
	}
	shape.draw(HSV(0, 1.0, 0.95));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center, Palette::Black);
}