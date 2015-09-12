#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

class Rule :
	public SceneManager<String, GameData>::Scene
{
private:
	Font title;
	Font subtitle;
	String ruleText1;
	String ruleText2[5];
	Font text;
	Circle player;
	Rect titleRect;

public:
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};

