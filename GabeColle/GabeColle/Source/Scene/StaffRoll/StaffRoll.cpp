#include "StaffRoll.h"

StaffRoll::StaffRoll() : sound_m(L"./Asset/BGM/bgm_maoudamashii_acoustic07.ogg", L"Game1BGM")
{
}

void StaffRoll::init()
{
	auto define_credit = [](StaffRollContent credit){return std::make_shared<StaffRollContent>(credit); };
	
	changeFrame_m = 200;
	contentNumber_m = 0;
	contents_m.push_back(define_credit(StaffRollContent(L"Title")));
	contents_m.push_back(define_credit(StaffRollContent(L"Programmer", { L"HataG", L"Jumpaku", L"Namba", L"Uhhyoi" ,L"����[��"})));
	contents_m.push_back(define_credit(StaffRollContent(L"BGM", { L"�������l", L"�t���[BGM�E���y�f�� \n	H/MIX GALLERY�l", L"Free BGM DOVA SYNDROME \n\t\t �������l" })));
	contents_m.push_back(define_credit(StaffRollContent(L"SE", { L"���炰�H���l" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Idea", { L"Jumpaku" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Graphic", { L"�C���X�g���l", L"/\\lex�l",L"Design Deck�l",L"HataG", L"Jumpaku" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Library", { L"Siv3D" })));
	contents_m.push_back(define_credit(StaffRollContent(L"Circle")));
	contents_m.push_back(define_credit(StaffRollContent(L"TitleLogo")));
	contents_m.push_back(define_credit(StaffRollContent(L"Finalize")));

	sound_m.startMusic();
}

void StaffRoll::update()
{
	if (Mouse::LeftClicked()){
		sound_m.stopMusic();
		this->changeScene(L"Start", 2000, false);
	}
	if (changeFrame_m == 0){
		if (sound_m.isEnded()){
			this->changeScene(L"Start", 2000, false);
		}
		if ((unsigned)contentNumber_m == contents_m.size() - 2){
			return;
		}
		contentNumber_m = (contentNumber_m + 1) % (contents_m.size());
		changeFrame_m = 200;
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