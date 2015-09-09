#include "Result.h"
Result::Result() : fontSize(30), resultText(fontSize), circleRadius(100), backGround(L"Asset/Image/GabeColle.png"), BGM(L"Asset/BGM/bgm_maoudamashii_cyber04.mp3"), texture(L"Asset/Image/resultBG2.png"), texture2(L"Asset/Image/resultBG.png")
{
	if (!BGM)
	{
		return;	// ロードに失敗したら終了
	}
}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Result::init()
{
	
	Record::decryptCSV();

	stageNode_m = new StageNameNode(this->m_data->stageName, 0, Window::Center());

	results_m[0] = new ResultNode(0,this->m_data->time, L"Time", 10, circle_time_m.center);
	results_m[1] = new ResultNode(1,this->m_data->numOfError, L"Errors", 20, circle_error_m.center);
	results_m[2] = new ResultNode(2,this->m_data->numOfDeletedObject, L"Processes", 30, circle_process_m.center);
	results_m[3] = new ResultNode(3,this->m_data->totalScore, L"Score", 40, circle_totalScore_m.center);
	Graphics::SetBackground(Palette::Darkblue);

	Record::encryptCSV();

	

	BGVelocity = 1;
	BG_X = 0;
	BG_X2 = texture.size.x;
}

// 毎フレーム updateAndDraw() で呼ばれる
void Result::update()
{
	
	BGM.play();
	stageNode_m->update();
	for (int i = 0; i < 4; ++i){
		results_m[i]->update();	
	}
	BG_X -= BGVelocity;
	BG_X2 -= BGVelocity;
	if (BG_X <= -texture.size.x){
		BG_X = texture.width;
	}
	if (BG_X2 <= -texture.size.x){
		BG_X2 = texture.width;
	}
	
}

// 毎フレーム update() の次に呼ばれる
void Result::draw() const
{
	
	texture.draw(BG_X,0);

	texture.mirror().draw(BG_X2, 0);
	
	//backGround.draw(Window::GetPos(), Alpha(180));
	stageNode_m->draw();
	for (int i = 0; i < 4; ++i){
		results_m[i]->draw();
	}
	
	
}