#pragma once

#include<Siv3D.hpp>

#include "ClickableBase.h"

namespace clickable {

class Button :
	public ClickableBase<RoundRect>
{
protected:
	static std::unique_ptr<Effect> effect_m;
	static String const FONT_ASSET_NAME;
	String soundName_m;
	HSV color_m;
	virtual void drawPressed(RoundRect shape, String const &text, int frame)const;
	virtual void drawOver(RoundRect shape, String const &text, int frame)const;
	virtual void drawLeft(RoundRect shape, String const &text, int frame)const;
	virtual void drawClicked(RoundRect shape, String const &text, int frame)const;
public:
	Button(Rect const &rect, String text, String soundName);
	Button(Rect const &rect, String text, int h, String soundName);
	static void drawEffect();

	virtual ~Button();
	void update()override;
};

}
