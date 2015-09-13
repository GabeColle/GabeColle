
# include <Siv3D.hpp>


#include "Source\Scene\Sample\Sample.h"
#include "Source\Scene\Start\Start.h"
#include "Source\Scene\GameSelect\GameSelect.h"
#include "Source\Scene\Game1\Game1.h"
#include "Source\Scene\Game2\Game2.h" 
#include"Source\Scene\Game3\Game3.h"
#include"Source\Scene\Result\Result.h"

void Main()
{
	Window::Resize(1280, 720);
	Window::Centering();
	Window::SetStyle(WindowStyle::NonFrame);

	SceneManager<String, GameData> manager(SceneManagerOption::None);

	// サウンドアセットに曲を追加
	SoundAsset::Register(L"Game2_BGM", L"Asset/BGM/bgm_maoudamashii_cyber09.ogg");
	SoundAsset::Register(L"GameSelect_BGM", L"Asset/BGM/bgm_maoudamashii_cyber07.ogg");

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::Black);


	// シーンを設定
	manager.add<Start>(L"Start");
	manager.add<GameSelect>(L"GameSelect");
	manager.add<Result>(L"Result");
	
	manager.add<Game1>(L"Game1");
	manager.add<Game2>(L"Game2");
	manager.add<Game2Easy>(L"Game2Easy");
	manager.add<Game2Hard>(L"Game2Hard");
	manager.add<Game3>(L"Game3");
	manager.add<Game3Easy>(L"Game3Easy");
	manager.add<Game3Hard>(L"Game3Hard");

	while (System::Update()) {
		if (!manager.updateAndDraw())
			break;
	}
}
