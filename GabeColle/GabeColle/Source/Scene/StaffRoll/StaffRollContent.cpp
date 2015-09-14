#include "StaffRollContent.h"

const int StaffRollContent::INIT_OBJECTS = 40;
const String StaffRollContent::titleFontHandle = L"TitleCall";


StaffRollContent::StaffRollContent(String contentName, Array<String> parties) : circleLogo(L"Asset/Image/MPC_clear.png"), titleLogo(L"Asset/Image/GabeColle.png")
{
	if (!FontAsset::IsRegistered(titleFontHandle)){
		FontAsset::Register(titleFontHandle, 80, Typeface::Medium, FontStyle::Italic);
	}
	parties_m = parties;
	
	memoryR_m = std::make_shared<staffroll::MemoryFromRoot>(staffroll::MemoryFromRoot(parties.size(), contentName, parties));
	init();
	state_m = contentName;
}

StaffRollContent::StaffRollContent(String contentName) : StaffRollContent(contentName, { L"" })
{
	if (contentName == L"Title"){
		state_m = L"firstTitle";
	}
	else if (contentName == L"Circle"){
		state_m = L"circleLogo";
	}
	else if (contentName == L"TitleLogo"){
		state_m = L"titleLogo";
	}
}

void StaffRollContent::init()
{
	memory_m.init();
	for (int i = 0; i < INIT_OBJECTS; ++i){
		memory_m.alloc();
		memoryR_m->alloc();
	}
}

void StaffRollContent::update()
{
	if (state_m == L"firstTitle"){

	}
	else if (state_m == L"circleLogo"){

	}
	else if (state_m == L"titleLogo"){

	}
	else{
		// ƒƒ‚ƒŠ‚ÌŠJ•ú
		if (!memory_m.getExistAddress().empty()){
			memory_m.free(memory_m.getExistAddress().at(Random(0, (int)memory_m.getExistAddress().size() - 1)));
		}
		memory_m.update();
		memoryR_m->update();
	}
	
}

void StaffRollContent::draw()const
{
	if (state_m == L"firstTitle"){
		FontAsset(titleFontHandle)(L"Gabage Collection\n	`‚ª‚×‚±‚ê`").drawCenter(Window::Center(), Palette::Blueviolet);
	}
	else if (state_m == L"circleLogo"){
		circleLogo.drawAt(Window::Center());
	}
	else if (state_m == L"titleLogo"){
		//titleLogo.scale(0.4).drawAt(Window::Center().movedBy(0, -120));
		DespiteOfScene::sendDrawingInstruction();
	}
	else{
		memory_m.draw();
		memoryR_m->draw();
	}
	
}