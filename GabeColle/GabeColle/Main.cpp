
# include <Siv3D.hpp>

#include"Source\Scene\Sample\Sample.h"
#include"Source\Scene\Start\Start.h"
#include "Source\Scene\Game1\Game1.h"
#include"Source\Scene\Rule\Rule.h"

void Main()
{
	Window::SetStyle(WindowStyle::NonFrame); 
	Window::Resize(1280, 720);
	Window::Centering();

	SceneManager<String, GameData> manager(SceneManagerOption::None);

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::White);

	// シーンを設定
	//manager.add<Start>(L"Start");
	manager.add<Rule>(L"Rule");
	manager.add<Game1>(L"Game1");

	while (System::Update()) {
		if (!manager.updateAndDraw())
			break;
	}
}
