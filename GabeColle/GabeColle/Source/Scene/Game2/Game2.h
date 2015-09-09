#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include<map>

#include"../GameData.h"

#include"../../GC/Memory.h"
#include"CircleObject.h"
#include"../../Utility/Button/Button.h" //
#include"../../Clickable/Button.h"
#include"TextField.h"

class Game2 :
	public SceneManager<String, GameData>::Scene
{
protected:
	typedef std::shared_ptr<clickable::Button> Button_t;

	gc::Memory<game2::CircleObject> memory_m;
	//Button button_m; //
	clickable::Button completionButton_m;
	clickable::Button resultButton_m;
	clickable::Button titleButton_m;
	//std::map<String, Button_t> buttons_m;
	const TextField textField_m;

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
		      //button_m(30,L"OK",100,100),
			  //button_m(Rect(200, 48).setCenter({ 100, 100 }), L"OK", L"Asset/SoundEffect/Decision.mp3"),
			  completionButton_m(Rect(200, 48).setCenter({ 100, 100 }), L"Completion", L"Asset/SoundEffect/Decision.mp3"),
			  resultButton_m(Rect(200, 48).setCenter({ 100, 150 }), L"Result", L"Asset/SoundEffect/Decision.mp3"),
			  titleButton_m(Rect(200, 48).setCenter({ 100, 200 }), L"Back to Title", L"Asset/SoundEffect/Decision.mp3"),
			  textField_m(30)
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