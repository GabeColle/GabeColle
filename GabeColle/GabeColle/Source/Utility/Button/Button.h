#pragma once
#include <Siv3D.hpp>

class Button
{
protected:
	int xPos_m;
	int yPos_m;
	int width_m;
	int height_m;
	String str_m;
	Font font_m;
	Color buttonColor_m;
	Color mouseoverButtonColor_m;
	Color textColor_m;
	Color mouseoverTextColor_m;
	Rect rect_m;

public:
	/*
	デフォルトコンストラクタ
	*/
	Button(){}
	/*
	コンストラクタ　
	引数: 名称、X座標、Y座標、幅、高さ、フォントサイズ
	*/
	Button(String str , int xPos = 0, int yPos = 0, int width = 100, int height = 50, int fontSize = 30);

	/*
	コンストラクタ　
	引数: 名称、X,Y座標、ボタンのサイズ、フォントサイズ
	*/
	Button(String str , Vec2 pos , Vec2 size = { 100, 50 }, int fontSize = 30);

	/*
	コンストラクタ　
	引数: フォントサイズ、名称、X座標、Y座標
	*/
	Button(int fontSize, String str, int xPos, int yPos);

	/*
	コンストラクタ　
	引数: フォントのサイズ、名称、X,Y座標
	*/
	Button(int fontSize, String str, Vec2 pos);

	/*
	デストラクタ
	*/
	~Button();

	/*
	ボタンが左クリックされるとtrueを返す
	*/
	bool leftClicked();

	/*
	ボタンを描画
	*/
	void draw() const;

	/*
	ボタンや文字の色を変える
	引数: ボタンの色、マウスオーバー時のボタンの色、文字の色、マウスオーバー時の文字の色
	*/
	void setColor(Color buttonColor = Palette::Lightgrey, Color mouseoverButtonColor = Palette::Yellowgreen, Color textColor = Palette::Red, Color mouseoverTextColor = Palette::Red);
	
protected:

	/*
	ボタンのサイズをテキストに合わせる
	*/
	void Button::setRectByFont();

	/*
	長方形に座標やサイズを適用
	*/
	void setRect();
};