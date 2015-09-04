#include "Result.h"
Result::Result() : fontSize(30), resultText(fontSize), circleRadius(100), stageNameText(100, Typeface::Bold, FontStyle::Italic), backGround(L"Asset/Image/GabeColle.png")
{
}

// クラスの初期化時に一度だけ呼ばれる（省略可）
void Result::init()
{
	Graphics::SetBackground(Palette::Silver);
	countups[0] = new CountUpEffect(this->m_data->time, 60,circle_time_m.center);
	countups[1] = new CountUpEffect(this->m_data->numOfError, 60,circle_error_m.center);
	countups[2] = new CountUpEffect(this->m_data->numOfDeletedObject, 60,circle_process_m.center);
	countups[3] = new CountUpEffect(this->m_data->totalScore, 60,circle_totalScore_m.center);

	circles[0] = new ExpandCircleEffect(circle_stage_m, 30, 0, Palette::Aqua);
	circles[1] = new ExpandCircleEffect(circle_time_m, 30, 10, Palette::Darkred);
	circles[2] = new ExpandCircleEffect(circle_error_m, 30, 20, Palette::Darkred);
	circles[3] = new ExpandCircleEffect(circle_process_m, 30, 30, Palette::Darkred);
	circles[4] = new ExpandCircleEffect(circle_totalScore_m, 30, 40, Palette::Darkred);

	arrows[0] = new ExtendArrowEffect(Line(circle_stage_m.center, circle_time_m.center), 30, 40);
	arrows[1] = new ExtendArrowEffect(Line(circle_stage_m.center, circle_error_m.center), 30, 50);
	arrows[2] = new ExtendArrowEffect(Line(circle_stage_m.center, circle_process_m.center), 30, 60);
	arrows[3] = new ExtendArrowEffect(Line(circle_stage_m.center, circle_totalScore_m.center), 30, 70);

	texts[0] = new FadeInAndDescendStringEffect(L"Time", 30, 40, Vec2(circle_time_m.center.x,circle_time_m.center.y+circleRadius));
	texts[1] = new FadeInAndDescendStringEffect(L"Errors", 30, 50, Vec2(circle_error_m.center.x,circle_error_m.center.y+circleRadius));
	texts[2] = new FadeInAndDescendStringEffect(L"Processes", 30, 60, Vec2(circle_process_m.center.x,circle_process_m.center.y+circleRadius));
	texts[3] = new FadeInAndDescendStringEffect(L"Score", 30, 70, Vec2(circle_totalScore_m.center.x,circle_totalScore_m.center.y+circleRadius));

}

// 毎フレーム updateAndDraw() で呼ばれる
void Result::update()
{
	//countedVariable_time->countUp();
	//countedVariable_error->countUp();
	//countedVariable_process->countUp();
	//countedVariable_totalScore->countUp();
	for (int i = 0; i < 5; ++i){
		circles[i]->update();
	}
	for (int i = 0; i < 4; ++i){
		arrows[i]->update();
		countups[i]->countUp();
		texts[i]->update();
	}

}

// 毎フレーム update() の次に呼ばれる
void Result::draw() const
{
	backGround.draw(Window::GetPos(), Alpha(180));

	stageNameText(this->m_data->stageName).drawCenter(circle_stage_m.center, Palette::Azure);

	for (int i = 0; i < 4; ++i){
		countups[i]->draw();
	}
	//countedVariable_time->draw(circle_time_m.center.x, circle_time_m.center.y);
	//countedVariable_error->draw(circle_error_m.center.x, circle_error_m.center.y);
	//countedVariable_process->draw(circle_process_m.center.x, circle_process_m.center.y);
	//countedVariable_totalScore->draw(circle_totalScore_m.center.x, circle_totalScore_m.center.y);

}