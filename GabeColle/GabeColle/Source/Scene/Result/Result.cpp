#include "Result.h"



Result::Result() : 
fontSize(30),
resultText(fontSize),
circleRadius(100),
tweet_m(Rect(40, 40, 128,128), L"Asset/SoundEffect/button83.ogg")
{
	
}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Result::init()
{
	Circle circle_stage =		Circle(Window::Center(),								circleRadius);
	Circle circle_time =		Circle(circle_stage.center.x / 2,						circle_stage.center.y / 2,						circleRadius);
	Circle circle_error =		Circle((Window::Width() + circle_stage.center.x) / 2,	circle_time.y,									circleRadius);
	Circle circle_process =		Circle(circle_time.x,									(Window::Height() + circle_stage.center.y) / 2, circleRadius);
	Circle circle_totalScore =	Circle(circle_error.x,									circle_process.y,								circleRadius);

	returnButton_m = circle_stage;

	Record::decryptData(this->m_data->stageName);

	stageNode_m = std::make_shared<StageNameNode>(StageNameNode(this->m_data->stageName, 0, Window::Center()));

	results_m[0] = std::make_shared<ResultNode>(ResultNode(0, this->m_data->time,				L"Time",	  10, circle_time.center));
	results_m[1] = std::make_shared<ResultNode>(ResultNode(1, this->m_data->numOfError,			L"Errors",	  20, circle_error.center));
	results_m[2] = std::make_shared<ResultNode>(ResultNode(2, this->m_data->numOfDeletedObject,	L"Processes", 30, circle_process.center));
	results_m[3] = std::make_shared<ResultNode>(ResultNode(3, this->m_data->totalScore,			L"Score",	  40, circle_totalScore.center));
	
	Graphics::SetBackground(Palette::Darkblue);

	Record::encryptData(this->m_data->stageName);

	
}

// 毎フレーム updateAndDraw() で呼ばれる
void Result::update()
{
	bg.update();
	tweet_m.update();

	stageNode_m->update();
	for (int i = 0; i < 4; ++i){
		results_m[i]->update();	
	}
	if (returnButton_m.leftClicked){
		this->changeScene(L"StaffRoll", 2000, false);
	}
	if (tweet_m.isClicked()){
		Twitter::OpenTweetWindow(L"ガベこれの" + this->m_data->stageName + L"で" + Format(this->m_data->totalScore) + L"点とったぜいえーい(テスト)\n#GabeColle #Siv3D");
	}
	/*if (ending_m.isClicked()){
		this->changeScene(L"StaffRoll");
	}*/
}

// 毎フレーム update() の次に呼ばれる
void Result::draw() const
{
	bg.draw();
	tweet_m.draw();

	stageNode_m->draw();
	for (int i = 0; i < 4; ++i){
		results_m[i]->draw();
	}
}