#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include<map>
#include<thread>
#include"../GameData.h"
#include"../../Clickable/Button.h"

class Start :
	public SceneManager<String, GameData>::Scene
{
private:
	typedef std::shared_ptr<clickable::Button> Button_t;

	Texture logo_m;
	Font const titleFont_m;
	String title_m;
	std::map<String, Button_t> buttons_m;
	std::map<String, GUI> guis_m;

	std::thread twitter_m;

	void initButtons();
public:
	Start();
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};

