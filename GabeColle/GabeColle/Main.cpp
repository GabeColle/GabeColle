
# include <Siv3D.hpp>


#include "Source\Scene\Sample\Sample.h"
#include "Source\Scene\Start\Start.h"
#include "Source\Scene\Game2\Game2.h" 
#include"Source\Scene\Game3\Game3.h"
#include"Source\Scene\Result\Result.h"

void Main()
{
	Window::SetStyle(WindowStyle::NonFrame); 
	Window::Resize(1280, 720);
	Window::Centering();

	SceneManager<String, GameData> manager(SceneManagerOption::None);

	// サウンドアセットに曲を追加
	SoundAsset::Register(L"Game2_BGM", L"Asset/BGM/bgm_maoudamashii_cyber09.ogg");

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::White);


	// シーンを設定
	manager.add<Start>(L"Start");
	manager.add<Result>(L"Result");
	
	manager.add<Game2>(L"Game2");
	manager.add<Game2Easy>(L"Game2Easy");
	manager.add<Game2Hard>(L"Game2Hard");
	manager.add<Game3>(L"Game3");

	while (System::Update()) {
		if (!manager.updateAndDraw())
			break;
	}
}
