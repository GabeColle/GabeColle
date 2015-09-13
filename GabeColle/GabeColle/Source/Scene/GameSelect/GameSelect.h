#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

#include"Tag.h"
#include"Effect.h"
//#include"../../Clickable/Button.h"
#include"GameSelectButton.h"
#include"../game2/TextField.h"

class GameSelect :
	public SceneManager<String, GameData>::Scene
{
protected:
	std::vector<gameselect::Tag> tag_m;
	std::vector<GameSelectButton>buttons_m;

	Effect lingEffect_m;
	Effect lineEffect_m;
	Font font_m;
	Array<Vec2> pts_m;
	Array<Vec2> pts2_m;	
	String pictureName_m;
	int alpha_m;

public:
	//�R���X�g���N�^
	GameSelect()
		:font_m(50, L"Georgia", FontStyle::Italic)
	{};

	//�f�X�g���N�^
	~GameSelect(){};

	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;

protected:
	void background();
	void fft();
};
