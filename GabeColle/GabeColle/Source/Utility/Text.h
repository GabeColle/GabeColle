#pragma once

#include<siv3D.hpp>
class Text
{
protected:
	Font font_m;
	String string_m;
	Vec2 center_m;
	Color color_m;
public:
	Text() = default;
	Text(Font const &font);
	Text(Font const &font, String const &string);
	Text(Font const &font, String const &string, Vec2 const &center_m, Color const &color);

	void font(Font const &font);
	Font font()const;
	void string(String const &string);
	String string()const;
	void color(Color const &color);
	Color color()const;
	void center(Vec2 const &center);
	Vec2 center()const;

	virtual void update();
	virtual void draw()const;
};

