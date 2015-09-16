#pragma once

#include <Siv3D.hpp>
#include "../../Clickable/Button.h"


class TwitterButton : public clickable::Button{
private:
	void drawPressed(RoundRect shape, String const &text, int frame)const;
	void drawOver(RoundRect shape, String const &text, int frame)const;
	void drawLeft(RoundRect shape, String const &text, int frame)const;
	void drawClicked(RoundRect rect, String const &text, int frame)const;
public:
	TwitterButton(Rect const &rect, String soundName);
	void update()override;
};