#include "TwitterButton.h"

TwitterButton::TwitterButton(Rect const &rect, String soundName) : Button(rect, L"", soundName)
{
	if (!TextureAsset::IsRegistered(L"twitterIcon")){
		TextureAsset::Register(L"twitterIcon", L"Asset/Image/TwitterLogo_#55acee.png");
	}
}

void TwitterButton::update()
{
	Button::update();

}

void TwitterButton::drawPressed(RoundRect shape, String const &text, int frame)const
{
	shape.moveBy(0.0, 2.0).draw(HSV(0, 0.0, 0.75));
	//FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center, Palette::Black);
	TextureAsset(L"twitterIcon").scale(0.07).drawAt(shape.rect.center);
}

void TwitterButton::drawOver(RoundRect shape, String const &text, int frame)const
{
	drawLeft(shape, text, frame);
}

void TwitterButton::drawLeft(RoundRect shape, String const &text, int frame)const
{
	shape.draw(HSV(0, 0.0, 1.00));
	//FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center, Palette::Black);
	TextureAsset(L"twitterIcon").scale(0.07).drawAt(shape.rect.center);

}

void TwitterButton::drawClicked(RoundRect shape, String const &text, int frame)const
{
	double t = static_cast<double>(frame);
	static Point clickPoint;
	if (frame <= 1) {
		clickPoint = Mouse::Pos();
	}
	shape.draw(HSV(0, 0.0, 0.85));
	//FontAsset(FONT_ASSET_NAME).drawCenter(text, shape.rect.center, Palette::Black);
	TextureAsset(L"twitterIcon").scale(0.07).drawAt(shape.rect.center);
}