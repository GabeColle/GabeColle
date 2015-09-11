#include"GameSelect.h"

using namespace gameselect;

void GameSelect::init(){

	SoundAsset(L"GameSelect_BGM").play();
	SoundAsset(L"GameSelect_BGM").setPosSec(0.5);

	tag_m.push_back({ L"Game1 Easy"		, L""			, L"Game1", Difficulty::easy	});
	tag_m.push_back({ L"Game1 Normal"	, L"Game1"		, L"Game1", Difficulty::normal	});
	tag_m.push_back({ L"Game1 Hard"		, L""			, L"Game1", Difficulty::hard	});
	tag_m.push_back({ L"Game2 Easy"		, L"Game2Easy"	, L"Game2", Difficulty::easy	});
	tag_m.push_back({ L"Game2 Normal"	, L"Game2"		, L"Game2", Difficulty::normal	});
	tag_m.push_back({ L"Game2 Hard"		, L"Game2Hard"	, L"Game2", Difficulty::hard	});
	tag_m.push_back({ L"Game3 Easy"		, L"Game3Easy"	, L"Game3", Difficulty::easy	});
	tag_m.push_back({ L"Game3 Normal"	, L"Game3"		, L"Game3", Difficulty::normal	});
	tag_m.push_back({ L"Game3 Hard"		, L"Game3Hard"	, L"Game3", Difficulty::hard	});
	
	
	String ok = L"Asset/SoundEffect/Decision.mp3";

	for (auto i = 0; i < tag_m.size(); ++i){
		Point pos = { (Window::Width()/4 * ( i/3 +1 ))  + (i%3)*40 -40, 70 * i + 100 };
		buttons_m.push_back(clickable::Button(Rect(350, 48).setCenter(pos), tag_m[i].buttonName, ok));
	}
	
	tag_m.push_back({ L"Rules", L"", L"Rules", Difficulty::normal });
	buttons_m.push_back(clickable::Button(Rect(350, 48).setCenter(Window::Width()*1/4-40,100+70*8), tag_m[tag_m.size()-1].buttonName, ok));

	tag_m.push_back({ L"BackToTitle", L"Start", L"Title", Difficulty::normal });
	buttons_m.push_back(clickable::Button(Rect(350, 48).setCenter(Window::Width() * 3 / 4 + 40, 100), tag_m[tag_m.size() - 1].buttonName, ok));

}

void GameSelect::update(){

	SoundAsset(L"GameSelect_BGM").play();

	for (auto& b : buttons_m){
		b.update(buttonEffect_m);
	}
	for (auto i = 0; i <tag_m.size(); ++i){
		if (buttons_m[i].isClicked()){
			SoundAsset(L"GameSelect_BGM").pause(1000);
			changeScene(tag_m[i].sceneName, 1000);
		}
	}
	fft();
	background();
	
}

void GameSelect::draw()const{
	lineEffect_m.update();
	lingEffect_m.update();

	for (auto& b : buttons_m){
		b.draw();
	}
	buttonEffect_m.update();
	
}



void GameSelect::fft(){
	
	Array<Vec2> pts;
	Array<Vec2> pts2;
	const auto fft = FFT::Analyze(SoundAsset(L"GameSelect_BGM"));
	for (auto i = 0; i < Window::Width(); i++)
	{
		const double size = Pow(fft.buffer[i], 0.6f) * 2500;
		pts.push_back({ i, Window::Height() - size +35});
		pts2.push_back({ Window::Width() - i, size -35});
	}
	LineString(pts).draw(1.0,HSV(System::FrameCount()*2,0.5,0.8));
	LineString(pts2).draw(1.0, HSV(System::FrameCount()*2,0.5,0.8));
	//lineEffect_m.add<LineEffect>(LineString(pts),HSV(System::FrameCount()));
}

void GameSelect::background(){
	if (Random(5) == 0){
		Vec2 pos = RandomVec2(Window::Width(), Window::Height());
		lingEffect_m.add<LingEffect>(pos, Random(100) + 50, RandomColorH(0.5, 0.8));
	}

}