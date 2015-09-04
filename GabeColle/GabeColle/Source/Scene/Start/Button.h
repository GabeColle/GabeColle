#pragma once

#include<Siv3D.hpp>

#include "ClickableBase.h"

namespace start {

class Button :
	public ClickableBase<RoundRect>
{
protected:
	static String const FONT_ASSET_NAME;
	String soundName_m;

	virtual void drawPressed(RoundRect shape, String const &text, int frame)const;
	virtual void drawOver(RoundRect shape, String const &text, int frame)const;
	virtual void drawLeft(RoundRect shape, String const &text, int frame)const;
	virtual void drawClicked(RoundRect rect, String const &text, int frame)const;
public:
	Button(Rect const &rect, String text, String soundName);
	virtual ~Button();
	void update()override;
};

}
