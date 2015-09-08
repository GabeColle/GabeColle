#include "Result.h"
Result::Result() : fontSize(30), resultText(fontSize), circleRadius(100), stageNameText(100, Typeface::Bold, FontStyle::Italic), backGround(L"Asset/Image/GabeColle.png")
{
}

// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
void Result::init()
{
	stageNode_m = new StageNameNode(this->m_data->stageName, 0, Window::Center());

	results_m[0] = new ResultNode(this->m_data->time, L"Time", 10, circle_time_m.center);
	results_m[1] = new ResultNode(this->m_data->numOfError, L"Errors", 20, circle_error_m.center);
	results_m[2] = new ResultNode(this->m_data->numOfDeletedObject, L"Processes", 30, circle_process_m.center);
	results_m[3] = new ResultNode(this->m_data->totalScore, L"Score", 40, circle_totalScore_m.center);
	Graphics::SetBackground(Palette::Silver);

	
}

// ���t���[�� updateAndDraw() �ŌĂ΂��
void Result::update()
{
	stageNode_m->update();
	for (int i = 0; i < 4; ++i){
		results_m[i]->update();
	}

}

// ���t���[�� update() �̎��ɌĂ΂��
void Result::draw() const
{
	backGround.draw(Window::GetPos(), Alpha(180));
	
	for (int i = 0; i < 4; ++i){
		results_m[i]->draw();
	}
	stageNode_m->draw();
}