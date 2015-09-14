
#include <Siv3D.hpp>


#include "Source\Scene\Game1\Game1.h"
#include"Source\Scene\Rule\Rule.h"
#include "Source\Scene\Sample\Sample.h"
#include "Source\Scene\Start\Start.h"
#include "Source\Scene\GameSelect\GameSelect.h"
#include "Source\Scene\Game1\Game1.h"
#include "Source\Scene\Game2\Game2.h" 
#include"Source\Scene\Game3\Game3.h"
#include"Source\Scene\Result\Result.h"
#include "Source\Scene\StaffRoll\StaffRoll.h"

void Main()
{
	Window::Resize(1280, 720);
	Window::Centering();
	Window::SetStyle(WindowStyle::NonFrame);

	SceneManager<String, GameData> manager(SceneManagerOption::None);

	// サウンドアセットに曲を追加
	SoundAsset::Register(L"Game2_BGM", L"Asset/BGM/bgm_maoudamashii_cyber09.ogg");
	SoundAsset::Register(L"GameSelect_BGM", L"Asset/BGM/bgm_maoudamashii_cyber07.ogg");

	// テクスチャアセットに画像を追加
	TextureAsset::Register(L"Title_SS", L"Asset/Image/StartScene.png");
	TextureAsset::Register(L"Game1_SS", L"Asset/Image/ScreenShot_Game1.png");
	TextureAsset::Register(L"Game2_SS", L"Asset/Image/ScreenShot_Game2.PNG");
	TextureAsset::Register(L"Game3_SS", L"Asset/Image/Game3Scene.png");

	// フェードイン・アウト時の色
	manager.setFadeColor(Palette::Black);

	DespiteOfScene::init();


	// シーンを設定
	manager.add<StaffRoll>(L"StaffRoll");
	manager.add<Start>(L"Start");
	manager.add<Result>(L"Result");
	
	manager.add<Rule>(L"Rule");
	manager.add<Start>(L"Start");
	manager.add<GameSelect>(L"GameSelect");
	
	
	manager.add<Game1>(L"Game1");
	manager.add<Game1Easy>(L"Game1Easy");
	manager.add<Game1Hard>(L"Game1Hard");
	manager.add<Game2>(L"Game2");
	manager.add<Game2Easy>(L"Game2Easy");
	manager.add<Game2Hard>(L"Game2Hard");
	manager.add<Game3>(L"Game3");
	manager.add<Game3Easy>(L"Game3Easy");
	manager.add<Game3Hard>(L"Game3Hard");

	//manager.init(L"Start");

	while (System::Update()) {
		Println(DespiteOfScene::isDrawingState_m);
		if (!manager.updateAndDraw())
			break;
		DespiteOfScene::draw();
	}
}
