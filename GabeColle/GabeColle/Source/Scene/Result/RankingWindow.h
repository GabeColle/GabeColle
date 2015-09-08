#pragma once

#include <Siv3D.hpp>
#include <algorithm>

class RankingWindow{
private:
	const int windowWidth = 500;
	const int windowHeight = 600;
	const int barWidth = 500;
	const int barHeight = 50;
	String title_m;
	RoundRect* window;
	Rect* bar;
	Line* divideLine[11];
	const CSVReader reader;
	const Font font_m[10];
	const Font titleFont;
	Vec2 titlePosition;
	Vec2 scorePosition[10];
	Array<int> ranking;
	int value_m;
	Rect* ownFilter;
public:
	RankingWindow(int id,int value);
	void update();
	void draw()const;
};