#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include<map>

#include"../GameData.h"
#include"../../GC/Memory.h"
#include"../../Clickable/CircleObject.h"
#include"LinkArrow.h"
#include"../../Clickable/Button.h"

class JumpakuGame :
	public SceneManager<String, GameData>::Scene
{
	static int const SIZE_m = 51;
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

	Font font100_m;
	Font font20_m;
	std::map<String, std::shared_ptr<clickable::Button>> buttons_m;

	int allocInterval_m = 30;
	int objectLinkInterval_m = 10;
	int rootLinkInterval_m = 60;
	int unlinkInterval_m = 1;

	int deletes_m = 0;
	void initButtons();

	void updateError();
	void updateObjects();
	void checkState();
	void saveScore();
public:
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;



	JumpakuGame();
	~JumpakuGame() = default;
};

