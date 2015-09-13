#pragma once

#include <Siv3d.hpp>

class ScrollFadeOutStringEffect{
private:
	int velocity = 2;
	Font drawingText_m;
	String defaultString_m;
	String fadedInString_m;
	Vec2 defaultPos_m;
	Vec2 fadedInPos_m;
	Circle node_m;
	int unClearRate;

	void fadeout();
	void fadein();
public:
	ScrollFadeOutStringEffect(String fadeout,String fadein,Circle node,Font font);
	void update();
	void draw()const;
};