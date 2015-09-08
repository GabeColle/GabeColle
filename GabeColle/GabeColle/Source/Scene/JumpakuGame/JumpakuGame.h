#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"
#include"../../GC/Memory.h"
#include"../../Clickable/CircleObject.h"
#include"LinkArrow.h"

class JumpakuGame :
	public SceneManager<String, GameData>::Scene
{
	static int const SIZE_m = 101;
	using LinkTable_t = std::array < std::array<LinkArrow, SIZE_m>, SIZE_m >;

	enum State
	{
		SEGMENTATION_FAULT,
		OUT_OF_MEMORY,
		VALID,
	};

	State state_m = VALID;
	gc::Memory<clickable::CircleObject> memory_m;
	void drawMemory()const;
	void drawError()const;
	long frame_m = 0;
	LinkTable_t linkArrowTable_m;

	int allocInterval_m = 30;
	int objectLinkInterval_m = 5;
	int rootLinkInterval_m = 30;
	int unlinkInterval_m = 2;

	void updateObjects();
	void checkState();
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

