#include "StaffRoll.h"

StaffRoll::StaffRoll() : sound_m(L"./Asset/BGM/bgm_maoudamashii_acoustic07.ogg", L"Game1BGM")
{
}

void StaffRoll::init()
{
	sceneTransitionCounter = 120;
	auto define_credit = [](StaffRollContent credit){return std::make_shared<StaffRollContent>(credit); };
	
	changeFrame_m = 160;
	contentNumber_m = 0;
	contents_m.push_back(define_credit(StaffRollContent(L"Title")));
	contents_m.push_back(define_credit(StaffRollContent(L"Programmer", { L"HataG", L"Jumpaku", L"Namba", L"Uhhyoi" ,L"ちゅーた"})));
	contents_m.push_back(define_credit(StaffRollContent(L"BGM", { L"魔王魂様", L"フリーBGM・音楽素材 \n	 H/MIX GALLERY様", L"Free BGM DOVA SYNDROME \n		 かずち様" })));
	contents_m.push_back(define_credit(StaffRollContent(L"SE", { L"くらげ工匠様" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Idea", { L"Jumpaku" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Graphic", { L"イラスト愛様", L"/\\lex様",L"HataG", L"Jumpaku" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Library", { L"Siv3D" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Circle")));
	contents_m.push_back(define_credit(StaffRollContent(L"TitleLogo")));

	sound_m.startMusic();
}

void StaffRoll::update()
{
	if (changeFrame_m == 0){
		contentNumber_m = (contentNumber_m + 1)%(contents_m.size());
		if (contentNumber_m == contents_m.size() - 1){
			this->changeScene(L"Start", 2000, false);
		}
		changeFrame_m = 160;
	}
	else{
		changeFrame_m--;
	}
	contents_m[contentNumber_m]->update();
	sound_m.update();
}

void StaffRoll::draw()const
{
	sound_m.drawSpectrum();
	contents_m[contentNumber_m]->draw();
}