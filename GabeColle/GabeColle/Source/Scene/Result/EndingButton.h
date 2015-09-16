#pragma once

#include <Siv3D.hpp>
#include "../../Clickable/Button.h"

class EndingButton : public clickable::Button{
private:
	void drawPressed(RoundRect shape, String const &text, int frame)const;
	void drawOver(RoundRect shape, String const &text, int frame)const;
	void drawLeft(RoundRect shape, String const &text, int frame)const;
	void drawClicked(RoundRect rect, String const &text, int frame)const;
public:
	EndingButton(Rect const &rect, String text, String soundName);
	void update()override;
};