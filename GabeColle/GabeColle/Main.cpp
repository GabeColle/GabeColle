
# include <Siv3D.hpp>

<<<<<<< HEAD
#include "Source\Scene\Sample\Sample.h"
#include "Source\Scene\Result\Result.h"
=======
#include"Source\Scene\Sample\Sample.h"
#include"Source\Scene\Start\Start.h"
>>>>>>> origin/develop

void Main()
{
	Window::SetStyle(WindowStyle::NonFrame); 
	Window::Resize(1280, 720);
	Window::Centering();

	SceneManager<String, GameData> manager(SceneManagerOption::None);

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::White);

	// シーンを設定
	manager.add<Result>(L"Result");

	while (System::Update()) {
		if (!manager.updateAndDraw())
			break;
	}
}
