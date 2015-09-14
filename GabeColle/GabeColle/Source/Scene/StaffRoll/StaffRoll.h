#pragma once

#include <Siv3D.hpp>
#include <HamFramework.hpp>
#include "MemoryWrapper.h"
#include "StaffRollContent.h"
#include "MySound.h"

#include"../GameData.h"

class StaffRoll
	: public SceneManager<String, GameData>::Scene
{
private:
	int changeFrame_m;
	int contentNumber_m;
	Array<std::shared_ptr<StaffRollContent>> contents_m;
	staffroll::MySound sound_m;
	int sceneTransitionCounter;
public:
	StaffRoll();
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};
