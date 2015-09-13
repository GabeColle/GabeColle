#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include"../GameData.h"
#include "Cir.h"
#include"../../Clickable/Button.h"


class Rule :
	public SceneManager<String, GameData>::Scene
{
private:
	Font title;
	Font subtitle;
	Font text;
	Rect titleRect;
	Cir cir[40];
	Circle back;
	Texture mainimage;

	Texture game1_m;
	Texture game2_m;
	Texture game3_m;

	Font click;
	Font font;
	bool backbutton;
	clickable::Button button_m;

public:
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;

	Rule();
};
