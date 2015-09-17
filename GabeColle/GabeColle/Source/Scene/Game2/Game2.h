#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

#include"../../GC/Memory.h"
#include"CircleObject.h"
#include"../../Clickable/Button.h"
#include"TextField.h"

class Game2 :
	public SceneManager<String, GameData>::Scene
{
protected:
	gc::Memory<game2::CircleObject> memory_m;
	clickable::Button completionButton_m;
	clickable::Button resultButton_m;
	clickable::Button titleButton_m;
	const TextField textField_m;
	const TextField reference_m;
	Effect effect_m;

	int NUM_OF_MEMORY = 12; 

	unsigned int time_m;
	unsigned int count_m;
	int garbage_m;
	int segmentFault_m;
	int process_m;

	String name_m = L"Game2(Normal)";

	const Vec2 rootPos = { Window::Width() / 2.0, Window::Height() / 2.0 };	

	enum class State{
		draw = 0, MtoM ,erase, input, result,
	}state;

public:
	//�R���X�g���N�^
	Game2() : memory_m(19),
		titleButton_m(Rect(300, 48).setCenter({ Window::Width() * 1 / 7, 80 }), L"Give up", L"Asset/SoundEffect/Decision.ogg"),
		completionButton_m(Rect(300, 48).setCenter({ Window::Width() * 1 / 7, 200 }), L"Complete", L"Asset/SoundEffect/Decision.ogg"),
		resultButton_m(Rect(300, 48).setCenter({ Window::Width() * 1 / 7, 200 }), L"Result", 30,L"Asset/SoundEffect/Decision.ogg"),		
		textField_m(30),
		reference_m(18)
	{};

	//�f�X�g���N�^
	~Game2(){};

	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;

private:
	int alloc(Vec2 pos);
	bool allocAndReferenceFromRoot(Vec2 pos);
	bool allocAndRefetenceMemoryToMemory(int address_t,Vec2 pos);

	void freeByInput();
	void countAndChangeState(bool isOutOfMemory);
	void seekSegmentFault();
	void drawBackGround() const;
	void drawStates() const;

};


#include"Game2Easy.h"
#include"Game2Hard.h"