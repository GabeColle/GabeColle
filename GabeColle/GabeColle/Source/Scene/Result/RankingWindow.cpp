#include "RankingWindow.h"

RankingWindow::RankingWindow(int id,int value) : reader(L"Source/Scene/Result/result.csv")
{
	
	title_m = reader.get<String>(0, id);
	value_m = value;
	window = new  RoundRect(Window::Center().x-windowWidth/2,Window::Center().y-windowHeight/2, windowWidth, windowHeight, 40);
	bar = new Rect(window->x, window->y, barWidth, barHeight);
	for (int i = 0; i < 11; ++i){
		divideLine[i] = new Line(window->x, bar->y + barHeight + i * 55, window->x + windowWidth, bar->y + barHeight + i * 55);
		
	}
	for (int i = 1; i < 11; ++i){
		ranking.push_back(reader.get<int>(i,id));
	}
	std::sort(ranking.begin(), ranking.end(), [](const int x, const int y) { return x > y; });
	ranking.pop_back();
	ranking.emplace_back(value_m);
	std::sort(ranking.begin(), ranking.end(), [](const int x, const int y) { return x > y; });
	titlePosition = Vec2(window->x + windowWidth / 2, window->y + barHeight / 2);
	for (int i = 0; i < 10; ++i){
		scorePosition[i] = Vec2(window->x + windowWidth / 2, (divideLine[i]->begin.y + divideLine[i + 1]->begin.y)/2);
	}
	int ownPosition = 0;
	for (int i = 0; i < 10; ++i){
		if (ranking[i] == value){
			ownPosition = i;
			break;
		}
	}
	ownFilter = new Rect(divideLine[ownPosition]->begin.x,divideLine[ownPosition]->begin.y, windowWidth, divideLine[ownPosition+1]->begin.y-divideLine[ownPosition]->begin.y);
}

void RankingWindow::update()
{

}

void RankingWindow::draw()const
{
	window->draw(Color(Palette::Darkred, 128));
	bar->draw(Color(Palette::Antiquewhite, 128));
	for (int i = 0; i < 11; ++i){
		divideLine[i]->draw();
	}
	titleFont(title_m).drawCenter(titlePosition, Palette::White);
	for (int i = 0; i < 10; ++i){
		font_m[i](Format(ranking[i])).drawCenter(scorePosition[i],Palette::White);
	}
	ownFilter->draw(Color(Palette::Aquamarine, 200));
}