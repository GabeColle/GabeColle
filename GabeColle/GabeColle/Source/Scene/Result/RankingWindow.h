#pragma once

#include <Siv3D.hpp>
#include <algorithm>
#include "../../Utility/Button/Button.h"
#include "Record.h"

class RankingWindow{
private:
	static const int WINDOW_WITDTH = 500;
	static const int WINDOW_HEIGHT = 600;
	static const int BAR_WIDTH = 500;
	static const int BAR_HEIGHT = 50;
	static const int LOWEST = 10;
	static const int BETWEEN_LINE = (WINDOW_HEIGHT - BAR_HEIGHT) / LOWEST;

	static String titles_m[4];

	String title_m;
	RoundRect* window;
	Rect* bar;
	Line* divideLine[LOWEST+1];
	
	Font drawingRankings_m[LOWEST];
	Font drawingTitle_m;
	Vec2 titlePosition_m;
	Vec2 scorePosition_m[LOWEST];
	Array<int> ranking_m;
	Rect* ownFilter_m;

	Button* closeButton_m;
	Button* initButton_m;

	void constructRankingWindow();
	void createRanking(int id,int value);
	int searchPosition(int value);

	void initRanking();
public:
	RankingWindow(int id,int value);
	void init(int id,int value);
	void draw()const;
	bool pushButton();
	void initPush();
};