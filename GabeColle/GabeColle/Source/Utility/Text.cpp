
#include "Text.h"

AbstractText::AbstractText(String const &string, Vec2 const &center, Color const &color)
	:string_m(string), center_m(center), color_m(color)
{}

void AbstractText::string(String const &string)
{
	string_m = string;
}

String AbstractText::string()const
{
	return string_m;
}

void AbstractText::color(Color const &color)
{
	color_m = color;
}

Color AbstractText::color()const
{
	return color_m;
}

void AbstractText::center(Vec2 const &center)
{
	center_m = center;
}

Vec2 AbstractText::center()const
{
	return center_m;
}

void AbstractText::update() {}



Text::Text(Font const &font) :Text(font, String())
{}

Text::Text(Font const &font, String const &string)
	:Text(font, string, Vec2(), Color())
{}

Text::Text(Font const &font, String const &string, Vec2 const &center, Color const &color)
	: AbstractText(string, center, color), font_m(font)
{}

void Text::font(Font const &font)
{
	font_m = font;
}

Font Text::font()const
{
	return font_m;
}

void Text::draw()const
{
	font_m(string_m).drawCenter(center_m, color_m);
}


FontSharedText::FontSharedText(String const &fontName)
	:FontSharedText(fontName, String(), Vec2(), Color())
{}

FontSharedText::FontSharedText(String const &fontName, String const &string)
	: FontSharedText(fontName, string, Vec2(), Color())
{}

FontSharedText::FontSharedText(String const &fontName, String const &string, Vec2 const &center, Color const &color)
	: AbstractText(string, center, color), fontName_m(fontName)
{
	assert(/*Font asset has been not registered*/
		FontAsset::IsRegistered(fontName_m));
}

void FontSharedText::draw()const
{
	FontAsset(fontName_m).drawCenter(string_m, center_m, color_m);
}
