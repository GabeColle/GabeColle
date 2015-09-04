
# include <Siv3D.hpp>

#include"Source\Scene\Sample\Sample.h"
#include"Source\Scene\Start\Start.h"

void Main()
{
	Window::SetStyle(WindowStyle::NonFrame); 
	Window::Resize(1280, 720);
	Window::Centering();

	SceneManager<String, GameData> manager(SceneManagerOption::None);

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::White);

	// シーンを設定
	manager.add<Start>(L"Start");
	manager.add<Sample>(L"Sample");

	while (System::Update()) {
		if (!manager.updateAndDraw())
			break;
	}
}
