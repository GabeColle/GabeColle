
# include <Siv3D.hpp>

#include"Source\Scene\Sample\Sample.h"

void Main()
{
	SceneManager<String, GameData> manager(SceneManagerOption::None);

	// SceneManagerOption::ShowSceneName を外せばシーン名のデバッグ表示は消える
	//MyApp manager;

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::White);

	// シーンを設定
	manager.add<Sample>(L"Sample");

	while (System::Update()) {
		if (!manager.updateAndDraw())
			break;
	}
}
