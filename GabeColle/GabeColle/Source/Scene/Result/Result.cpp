#include "Result.h"
Result::Result() : fontSize(30), resultText(fontSize), circleRadius(100)
{
	
}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Result::init()
{
	Circle circle_stage = Circle(Window::Center(), circleRadius);
	Circle circle_time = Circle(circle_stage.center.x / 2, circle_stage.center.y / 2, circleRadius);
	Circle circle_error = Circle((Window::Width() + circle_stage.center.x) / 2, circle_time.y, circleRadius);
	Circle circle_process = Circle(circle_time.x, (Window::Height() + circle_stage.center.y) / 2, circleRadius);
	Circle circle_totalScore = Circle(circle_error.x, circle_process.y, circleRadius);

	Record::decryptData();

	stageNode_m = new StageNameNode(this->m_data->stageName, 0, Window::Center());

	results_m[0] = new ResultNode(0,this->m_data->time, L"Time", 10, circle_time.center);
	results_m[1] = new ResultNode(1,this->m_data->numOfError, L"Errors", 20, circle_error.center);
	results_m[2] = new ResultNode(2,this->m_data->numOfDeletedObject, L"Processes", 30, circle_process.center);
	results_m[3] = new ResultNode(3,this->m_data->totalScore, L"Score", 40, circle_totalScore.center);
	Graphics::SetBackground(Palette::Darkblue);

	Record::encryptData();
}

// 毎フレーム updateAndDraw() で呼ばれる
void Result::update()
{
	bg.update();

	stageNode_m->update();
	for (int i = 0; i < 4; ++i){
		results_m[i]->update();	
	}
	
}

// 毎フレーム update() の次に呼ばれる
void Result::draw() const
{
	bg.draw();

	stageNode_m->draw();
	for (int i = 0; i < 4; ++i){
		results_m[i]->draw();
	}
}