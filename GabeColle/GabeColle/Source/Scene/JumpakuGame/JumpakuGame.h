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

public:
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override
	{
		memory_m.root().alloc(0);
	}

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override
	{
		memory_m.root().update();
		if (Mouse::LeftClicked()) {
			auto p = memory_m.alloc();
			if (p != 0) {
				memory_m.access(p).alloc(p);
			}
		}
		for (int i(1); i < memory_m.size(); ++i) {
			if (!memory_m.hasExpired(i)) {
				memory_m.access(i).update();
			}
		}
	}

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override
	{
		drawMemory(memory_m);
	}
	JumpakuGame();
	~JumpakuGame() = default;
};

