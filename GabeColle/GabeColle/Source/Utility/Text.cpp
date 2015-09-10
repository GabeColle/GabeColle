#include "Text.h"

Text::Text(Font const &font) :Text(font, L"") {}

Text::Text(Font const &font, String const &string)
	:font_m(font), string_m(string)
{}

void Text::font(Font const &font)
{
	font_m = font;
}

Font Text::font()const
{
	return font_m;
}

void Text::string(String const &string)
{
	string_m = string;
}

String Text::string()const
{
	return string_m;
}

void Text::color(Color const &color)
{
	color_m = color;
}

Color Text::color()const
{
	return color_m;
}

void Text::center(Vec2 const &center)
{
	center_m = center;
}

Vec2 Text::center()const
{
	return center_m;
}

void Text::update() {}

void Text::draw()const
{
	font_m(string_m).drawCenter(center_m, color_m);
}