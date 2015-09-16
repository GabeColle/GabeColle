#include "StaffRollContent.h"

const int StaffRollContent::INIT_OBJECTS = 40;
const String StaffRollContent::titleJapaneseFontHandle = L"JapaneseTitle";
const String StaffRollContent::titleEnglishFontHandle = L"EnglishTitle";
const String StaffRollContent::circleLogoHandle = L"CircleCall";


StaffRollContent::StaffRollContent(String contentName, Array<String> parties)
{
	if (!FontAsset::IsRegistered(titleJapaneseFontHandle)){
		FontAsset::Register(titleJapaneseFontHandle, 30, L"IPA P–¾’©");
	}
	if (!FontAsset::IsRegistered(titleEnglishFontHandle)){
		FontAsset::Register(titleEnglishFontHandle, 30,L"IPA P–¾’©");
	}
	if (!TextureAsset::IsRegistered(circleLogoHandle)){
		TextureAsset::Register(circleLogoHandle,L"Asset/Image/mpc_clear.png");
	}
	parties_m = parties;
	
	memoryR_m = std::make_shared<staffroll::MemoryFromRoot>(staffroll::MemoryFromRoot(contentName, parties));
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
	else if (contentName == L"Finalize"){
		state_m = L"finalize";
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
	else if (state_m == L"finalize"){

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
		FontAsset(titleEnglishFontHandle)(L"G a r b a g e C o l l e c t i o n").drawCenter(Window::Center(), Palette::Whitesmoke);
		FontAsset(titleJapaneseFontHandle)(L"~ ƒK ƒx ‚± ‚ê ~").drawCenter(Window::Center().movedBy(0,FontAsset(titleJapaneseFontHandle).size+40), Palette::Whitesmoke);
	}
	else if (state_m == L"circleLogo"){
		TextureAsset(circleLogoHandle).scale(0.8).drawAt(Window::Center());
	}
	else if (state_m == L"titleLogo"){
		DespiteOfScene::sendDrawingInstruction();
	}
	else if (state_m == L"finalize"){

	}
	else{
		memory_m.draw();
		memoryR_m->draw();
	}
}