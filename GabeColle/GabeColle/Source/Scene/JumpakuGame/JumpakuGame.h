#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"
#include"../../GC/Memory.h"
#include"../../Clickable/CircleObject.h"

class JumpakuGame :
	public SceneManager<String, GameData>::Scene
{
	gc::Memory<clickable::CircleObject> memory_m;
	void drawMemory(gc::Memory<clickable::CircleObject> const &memory)const;
	long frame_m = 0;
public:
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;

	JumpakuGame();
	~JumpakuGame() = default;
};

