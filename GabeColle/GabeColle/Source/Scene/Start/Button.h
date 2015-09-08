#pragma once

#include "ButtonInterface.h"

namespace start {

class Button :
	public ButtonInterface
{
protected:
	enum State
	{
		PRESSED,
		OVER,
		LEFT,
		CLICKED,
	};
	static String const FONT_ASSET_NAME;
	String soundName_m;
	RoundRect rect_m;
	String text_m;
	int frame_m = 0;
	State state_m = LEFT;

	virtual void changeState();
	virtual void drawRessed(RoundRect rect, String const &text, int frame)const;
	virtual void drawOver(RoundRect rect, String const &text, int frame)const;
	virtual void drawLeft(RoundRect rect, String const &text, int frame)const;
	virtual void drawClicked(RoundRect rect, String const &text, int frame)const;
public:
	Button(Rect const &rect, String text, String soundName);
	virtual ~Button();
	void update()override;
	void draw()override;
	bool isClicked()const override;
};

}
