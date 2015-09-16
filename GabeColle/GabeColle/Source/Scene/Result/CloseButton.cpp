#include "CloseButton.h"

CloseButton::CloseButton(Rect const &rect, String text, String soundName) : Button(rect, text, soundName)
{

}

void CloseButton::update()
{
	Button::update();
}

void CloseButton::drawPressed(RoundRect shape, String const &text, int frame)const
{
	shape.moveBy(0.0, 2.0).draw(HSV(0, 1.0, 0.75));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center,Palette::Black);
}

void CloseButton::drawOver(RoundRect shape, String const &text, int frame)const
{
	drawLeft(shape,text,frame);
}

void CloseButton::drawLeft(RoundRect shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 1.0, 0.85));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center,Palette::Black);
}

void CloseButton::drawClicked(RoundRect shape, String const &text, int frame)const
{
	static Point clickPoint;
	if (frame <= 1) {
		clickPoint = Mouse::Pos();
	}
	shape.draw(HSV(0, 1.0, 0.95));
	FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center,Palette::Black);
}