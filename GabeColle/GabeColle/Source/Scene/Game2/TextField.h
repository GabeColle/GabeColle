#pragma once 
#include <Siv3D.hpp>

class TextField{
protected:
	Font font_m;

public:
	TextField(){}
	TextField(int fontSize) : font_m(fontSize){}
	~TextField(){}

	void draw(Vec2 pos, String text,Vec2 size)const{
		RoundRect(pos, size, 10).draw(Color(Palette::Darkgray,200));
		RoundRect(pos, size, 10).drawFrame(0.5, 0.5, Color(Palette::Gold, 255));
		font_m(text).draw({ pos.x + 10, pos.y }, Palette::White);
		//font_m(val).draw({ pos.x + 330 - static_cast<int>(font_m(val).region().w)/30*30, pos.y +60 }, Palette::White);
	}
};