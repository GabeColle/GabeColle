#include "RankingWindow.h"

String RankingWindow::titles_m[4];

RankingWindow::RankingWindow(int id,int value)
{
	init(id, value);
}

void RankingWindow::init(int id,int value)
{
	constructRankingWindow();

	const int WINDOW_CENTER_X = (int)window->x + WINDOW_WITDTH / 2;

	titles_m[0] = L"経過時間";
	titles_m[1] = L"発生したエラー数";
	titles_m[2] = L"削除したプロセス数";
	titles_m[3] = L"合計得点";

	createRanking(id, value);
	titlePosition_m = Vec2(WINDOW_CENTER_X, window->y + BAR_HEIGHT / 2);
	for (int i = 0; i < 10; ++i){
		scorePosition_m[i] = Vec2(WINDOW_CENTER_X, (divideLine[i]->begin.y + divideLine[i + 1]->begin.y) / 2);
	}

	int ownPosition = searchPosition(value);
	if (ownPosition != -1){
		ownFilter_m = new Rect((int)divideLine[ownPosition]->begin.x, (int)divideLine[ownPosition]->begin.y, WINDOW_WITDTH, BETWEEN_LINE);
	}

	closeButton_m = new Button(L"x", (int)window->x + WINDOW_WITDTH - 40, (int)window->y, 40, BAR_HEIGHT);
}
void RankingWindow::draw()const
{
	window->draw(Color(Palette::Darkred, 128));
	bar->draw(Color(Palette::Antiquewhite, 128));
	for (int i = 0; i < 11; ++i){
		divideLine[i]->draw();
	}
	drawingTitle_m(title_m).drawCenter(titlePosition_m, Palette::White);
	for (int i = 0; i < 10; ++i){
		drawingRankings_m[i](Format(ranking_m[i])).drawCenter(scorePosition_m[i],Palette::White);
	}
	if (ownFilter_m != NULL){
		ownFilter_m->draw(Color(Palette::Aquamarine, 200));
	}
	closeButton_m->draw();
}

void RankingWindow::constructRankingWindow()
{
	window = new RoundRect(Window::Center().x - WINDOW_WITDTH / 2, Window::Center().y - WINDOW_HEIGHT / 2, WINDOW_WITDTH, WINDOW_HEIGHT, 40);
	bar = new Rect((int)window->x, (int)window->y, BAR_WIDTH, BAR_HEIGHT);
	for (int i = 0; i < LOWEST+1; ++i){
		divideLine[i] = new Line(window->x, bar->y + BAR_HEIGHT + i * BETWEEN_LINE, window->x + WINDOW_WITDTH, bar->y + BAR_HEIGHT + i * BETWEEN_LINE);
	}
}


void RankingWindow::createRanking(int id,int value)
{
	title_m = titles_m[id];
	for (int i = 0; i < LOWEST; ++i){
		ranking_m.push_back(Record::rankingData_m[id][i]);
	}
	ranking_m.push_back(value);
	std::sort(ranking_m.begin(), ranking_m.end(), 
		[id](const int x, const int y) { 
		if (id < 2) return x < y; 
		else return x > y; });
	ranking_m.pop_back();
	for (int i = 0; i < LOWEST; ++i){
		Record::rankingData_m[id][i] = ranking_m.at(i);	
	}
}

int RankingWindow::searchPosition(int value)
{
	for (int i = 0; i < LOWEST; ++i){
		if (ranking_m[i] == value){
			return i;
		}
	}
	return -1;
}


bool RankingWindow::pushButton()
{
	return closeButton_m->leftClicked();
}

