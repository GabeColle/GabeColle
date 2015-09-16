#pragma once

#include <Siv3D.hpp>
#include <algorithm>
#include "CloseButton.h"
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

private:
	std::shared_ptr<Rect> window_m;
	std::shared_ptr<Rect> bar_m;
	std::shared_ptr<Rect> ownFilter_m;
	std::shared_ptr<Line> divideLine_m[LOWEST+1];
	std::shared_ptr<CloseButton> closeButton_m;
	
	String title_m;
	
	
	Font drawingRankings_m[LOWEST];
	Font drawingTitle_m;

	Vec2 titlePosition_m;
	Vec2 scorePosition_m[LOWEST];

	Array<int> ranking_m;

private:
	void constructRankingWindow();
	void createRanking(int id,int value);
	int searchPosition(int value);

public:
	RankingWindow(int id,int value);
	void init(int id,int value);
	void draw()const;
	bool pushButton();
};