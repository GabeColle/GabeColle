#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>
#include"../GameData.h"
#include "Cir.h"

class Rule :
	public SceneManager<String, GameData>::Scene
{
private:
	Font title;
	Font subtitle;
	Font text;
	Rect titleRect;
	Cir cir[10];

public:
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};
