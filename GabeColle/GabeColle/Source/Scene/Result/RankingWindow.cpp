#include "RankingWindow.h"

//int RankingWindow::rankingData_m[4][10];
String RankingWindow::titles_m[4];

RankingWindow::RankingWindow(int id,int value)
{
	titles_m[0] = L"経過時間";
	titles_m[1] = L"発生したエラー数";
	titles_m[2] = L"削除したプロセス数";
	titles_m[3] = L"合計得点";

	constructRankingWindow();
	createRanking(id,value);
	titlePosition = Vec2(window->x + WINDOW_WITDTH / 2, window->y + BAR_HEIGHT / 2);
	for (int i = 0; i < 10; ++i){
		scorePosition[i] = Vec2(window->x + WINDOW_WITDTH / 2, (divideLine[i]->begin.y + divideLine[i + 1]->begin.y)/2);
	}
	int ownPosition = searchPosition(value);
	ownFilter = new Rect(divideLine[ownPosition]->begin.x,divideLine[ownPosition]->begin.y, WINDOW_WITDTH, BETWEEN_LINE);

	closeButton_m = new Button(L"x",window->x+WINDOW_WITDTH-40,window->y,40,BAR_HEIGHT);
	initButton_m = new Button(L"☠", 30, Window::Height()-30, 40, 40);
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
	ownFilter->draw(Color(Palette::Aquamarine, 200)); closeButton_m->draw();
	closeButton_m->draw();
	initButton_m->draw();
	

}

void RankingWindow::constructRankingWindow()
{
	window = new  RoundRect(Window::Center().x - WINDOW_WITDTH / 2, Window::Center().y - WINDOW_HEIGHT / 2, WINDOW_WITDTH, WINDOW_HEIGHT, 40);
	bar = new Rect(window->x, window->y, BAR_WIDTH, BAR_HEIGHT);
	for (int i = 0; i < LOWEST+1; ++i){
		divideLine[i] = new Line(window->x, bar->y + BAR_HEIGHT + i * BETWEEN_LINE, window->x + WINDOW_WITDTH, bar->y + BAR_HEIGHT + i * BETWEEN_LINE);
	}
}


void RankingWindow::createRanking(int id,int value)
{
	title_m = titles_m[id];
	for (int i = 0; i < LOWEST; ++i){
		ranking.push_back(Record::rankingData_m[id][i]);
	}
	std::sort(ranking.begin(), ranking.end(), [](const int x, const int y) { return x > y; });
	ranking.pop_back();
	ranking.emplace_back(value);
	std::sort(ranking.begin(), ranking.end(), [](const int x, const int y) { return x > y; });
	for (int i = 0; i < LOWEST; ++i){
		Record::rankingData_m[id][i] = ranking.at(i);
		
	}
}

int RankingWindow::searchPosition(int value)
{
	for (int i = 0; i < LOWEST; ++i){
		if (ranking[i] == value){
			return i;
		}
	}
}


bool RankingWindow::pushButton()
{
	return closeButton_m->leftClicked();
}


void RankingWindow::initRanking()
{
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 10; ++j){
			Record::rankingData_m[i][j] = 0;
		}
	}
	Record::encryptCSV();
}

void RankingWindow::initPush()
{
	if (initButton_m->leftClicked()){
		initRanking();
	}
}