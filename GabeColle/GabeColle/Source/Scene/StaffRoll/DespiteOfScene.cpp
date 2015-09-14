#include "DespiteOfScene.h"

bool DespiteOfScene::isDrawingState_m = false;
String DespiteOfScene::titleLogo = L"TitleLogo";

void DespiteOfScene::init()
{
	if (!TextureAsset::IsRegistered(titleLogo)){
		TextureAsset::Register(titleLogo, L"Asset/Image/GabeColle.png");
	}
}

void DespiteOfScene::sendDrawingInstruction()
{
	isDrawingState_m = true;
}

void DespiteOfScene::sendNotDrawingInstruction()
{
	isDrawingState_m = false;
}

void DespiteOfScene::draw()
{
	if (isDrawingState_m){
		//titleLogo.scale(0.4).drawAt(Window::Center().movedBy(0,-120));
		TextureAsset(titleLogo).scale(0.4).drawAt(Window::Center().movedBy(0, -120));
	}
}
