#pragma once

#include<siv3D.hpp>

class TextInterface
{
public:
	virtual void string(String const &string) = 0;
	virtual String string()const = 0;
	virtual void color(Color const &color) = 0;
	virtual Color color()const = 0;
	virtual void center(Vec2 const &center) = 0;
	virtual Vec2 center()const = 0;
	virtual void update() = 0;
	virtual void draw()const = 0;
	virtual ~TextInterface() = default;
};

class AbstractText : public TextInterface
{
protected:
	String string_m;
	Vec2 center_m;
	Color color_m;
public:
	AbstractText() = default;
	AbstractText(String const &string, Vec2 const &center, Color const &color);

	virtual void string(String const &string);
	virtual String string()const;
	virtual void color(Color const &color);
	virtual Color color()const;
	virtual void center(Vec2 const &center);
	virtual Vec2 center()const;
	virtual void update();
	virtual ~AbstractText() = default;
};

class Text : public AbstractText
{
protected:
	Font font_m;
public:
	Text() = default;
	Text(Font const &font);
	Text(Font const &font, String const &string);
	Text(Font const &font, String const &string, Vec2 const &center_m, Color const &color);
	virtual ~Text() = default;

	void font(Font const &font);
	Font font()const;

	virtual void draw()const;
};

class FontSharedText : public AbstractText
{
protected:
	String fontName_m;
public:
	FontSharedText() = default;
	FontSharedText(String const &fontName);
	FontSharedText(String const &fontName, String const &string);
	FontSharedText(String const &fontName, String const &string, Vec2 const &center, Color const &color);
	
	void font(Font const &font);
	Font font()const;

	virtual void draw()const;

	virtual ~FontSharedText() = default;
};

class OutlineText : public AbstractText
{
	Font font_m;
public:
	void font(Font const &font);
	Font font()const; 
	void style(TextOutlineStyle const &style);
	void draw()const override;
};