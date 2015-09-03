#include "Result.h"
Result::Result() : fontSize(30), resultText(fontSize), circleRadius(100)
{
}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Result::init()
{
	countedVariable_time = new CountUpEffect(this->m_data->time, 60);
	countedVariable_error = new CountUpEffect(this->m_data->numOfError, 60);
	countedVariable_process = new CountUpEffect(this->m_data->numOfDeletedObject, 60);
	countedVariable_totalScore = new CountUpEffect(this->m_data->totalScore, 60);
}

// 毎フレーム updateAndDraw() で呼ばれる
void Result::update()
{
	countedVariable_time->countUp();
	countedVariable_error->countUp();
	countedVariable_process->countUp();
	countedVariable_totalScore->countUp();
}

// 毎フレーム update() の次に呼ばれる
void Result::draw() const
{
	resultText(resultSentence).draw(10, 0, Palette::White, 2.2);
	circle_stage_m.draw(Color(Palette::Aqua, 128)).drawFrame(0.0, 3.0, Palette::Aqua);
	circle_time_m.draw(Color(Palette::Darkred, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
	circle_error_m.draw(Color(Palette::Darkred, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
	circle_process_m.draw(Color(Palette::Darkred, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
	circle_totalScore_m.draw(Color(Palette::Darkred, 128)).drawFrame(0.0, 3.0, Palette::Darkred);

	countedVariable_time->draw(circle_time_m.center.x, circle_time_m.center.y);
	countedVariable_error->draw(circle_error_m.center.x, circle_error_m.center.y);
	countedVariable_process->draw(circle_process_m.center.x, circle_process_m.center.y);
	countedVariable_totalScore->draw(circle_totalScore_m.center.x, circle_totalScore_m.center.y);
}