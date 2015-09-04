#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

#include"../../GC/Memory.h"

#include"CircleObject.h"
#include"Controller.h"

class Game2 :
	public SceneManager<String, GameData>::Scene
{
private:
	gc::Memory<CircleObject> memory_m;
	Controller gui;

	unsigned time_m;
	
public:
	Game2() : memory_m(100){};
	~Game2(){};

	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;

private:
	void alloc();
};
