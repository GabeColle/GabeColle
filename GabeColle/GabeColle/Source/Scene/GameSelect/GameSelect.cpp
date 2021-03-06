#include"GameSelect.h"

using namespace gameselect;

void GameSelect::init(){

	SoundAsset(L"GameSelect_BGM").play();
	SoundAsset(L"GameSelect_BGM").setPosSec(0.5);

	font_m.changeOutlineStyle(TextOutlineStyle(Palette::Black, Palette::White, 1.0));

	pts_m.resize(Window::Width());
	pts2_m.resize(Window::Width());

	tag_m.push_back({ L"Game1 Easy"		, L"Game1Easy"	, L"Game1", Difficulty::easy	});
	tag_m.push_back({ L"Game1 Normal"	, L"Game1"		, L"Game1", Difficulty::normal	});
	tag_m.push_back({ L"Game1 Hard"		, L"Game1Hard"	, L"Game1", Difficulty::hard	});
	tag_m.push_back({ L"Game2 Easy"		, L"Game2Easy"	, L"Game2", Difficulty::easy	});
	tag_m.push_back({ L"Game2 Normal"	, L"Game2"		, L"Game2", Difficulty::normal	});
	tag_m.push_back({ L"Game2 Hard"		, L"Game2Hard"	, L"Game2", Difficulty::hard	});
	tag_m.push_back({ L"Game3 Easy"		, L"Game3Easy"	, L"Game3", Difficulty::easy	});
	tag_m.push_back({ L"Game3 Normal"	, L"Game3"		, L"Game3", Difficulty::normal	});
	tag_m.push_back({ L"Game3 Hard"		, L"Game3Hard"	, L"Game3", Difficulty::hard	});
	
	int hs[9] = { 20, 10, 0, 90, 100, 110, 180, 190, 200 };
	String ok = L"Asset/SoundEffect/Decision.ogg";

	for (unsigned i = 0; i < tag_m.size(); ++i){
		Point pos = { (Window::Width()/4 * ( i/3 +1 ))  + (i%3)*40 -40, 70 * i + 100 };
		Size size = { 350, 48 };
		auto btn = GameSelectButton(
			Rect(size).setCenter(pos), tag_m[i].buttonName, /*(90)*(i/3)-(10*i)+20*/hs[i], ok);
		btn.show();
		buttons_m.push_back(btn);
	}

	tag_m.push_back({ L"BackToTitle", L"Start", L"Title", Difficulty::normal });
	buttons_m.push_back(GameSelectButton(Rect(350, 48).setCenter(Window::Width() * 1 / 4 - 40, 100+70*8), tag_m[tag_m.size() - 1].buttonName, 270 ,ok));

}

void GameSelect::update(){

	static int frameCounter = 0;
	if(frameCounter >= 60 * 90) {
		frameCounter = 0;
		SoundAsset(L"GameSelect_BGM").pause(1000);
		changeScene(L"Start", 1000);
		return;
	}
	else {
		++frameCounter;
	}

	SoundAsset(L"GameSelect_BGM").play();

	for (auto& b : buttons_m){
		b.update();
	}
	for (unsigned i = 0; i < buttons_m.size(); ++i){
		if(buttons_m[i].isMouceOver()) {
			pictureName_m = Format(tag_m[i].gameName, L"_SS");
			alpha_m = 96;
		}
	}
	alpha_m-=2;
	alpha_m = Max(0,alpha_m);

	for (unsigned i = 0; i <tag_m.size(); ++i){
		if (buttons_m[i].isClicked()){
			SoundAsset(L"GameSelect_BGM").pause(1000);
			changeScene(tag_m[i].sceneName, 1000);
		}
	}
	fft();
	background();
	
}

void GameSelect::draw()const{

	//Graphics::SetBackground(HSV(System::FrameCount() * 2 + 60,0.2,0.9));
	if (pictureName_m!=L""){
		TextureAsset(pictureName_m).drawAt(Window::Center(), Color(255, 255, 255, alpha_m));
	}

	const Point pos = { Window::Width() * 3 / 4 - 60, 160 };
	font_m(L"Game Select").drawCenter({ pos.x + 4, pos.y + 4 }, HSV(System::FrameCount() + 170, 0.5, 0.4));
	font_m(L"Game Select").drawCenter(pos, HSV(System::FrameCount() + 180, 0.5, 0.8));

	lineEffect_m.update();
	lingEffect_m.update();

	for (auto& b : buttons_m){
		//b.drawShadow();
		b.draw();
	}
	
	clickable::Button::drawEffect();
	
}

void GameSelect::fft(){

	const auto fft = FFT::Analyze(SoundAsset(L"GameSelect_BGM"));
	for (auto i = 0; i < Window::Width(); i++)
	{
		const double size = Pow(fft.buffer[i], 0.6f) * 2500;
		pts_m[i] = { i, Window::Height() - size +35};
		pts2_m[i] = { Window::Width() - i, size -35};
	}
	//LineString(pts_m).moveBy({ 3, 3 }).draw(2.0, Color(HSV(System::FrameCount() * 2, 0.2, 0.2), 127));
	LineString(pts_m).draw(2.0, HSV(System::FrameCount() * 2, 0.5, 0.8));
	//LineString(pts2_m).moveBy({ 3, 3 }).draw(2.0, Color(HSV(System::FrameCount() * 2, 0.2, 0.2),127));
	LineString(pts2_m).draw(2.0, HSV(System::FrameCount()*2,0.5,0.8));
	//lineEffect_m.add<LineEffect>(LineString(pts),HSV(System::FrameCount()));
}

void GameSelect::background(){
	if (Random(5) == 0){
		Vec2 pos = RandomVec2(Window::Width(), Window::Height());
		lingEffect_m.add<LingEffect>(pos, Random(100) + 50, RandomColorH(0.5, 0.8));
	}

}