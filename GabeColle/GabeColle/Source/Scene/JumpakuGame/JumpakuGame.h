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
		VALID,
		GAME_OVER,
		CLEAR,
	};

	State state_m = VALID;
	gc::Memory<clickable::CircleObject> memory_m;
	int deletes_m = 0;
	LinkTable_t linkArrowTable_m;

	long frame_m = 0;
	long CLEAR_LIMIT_m = 10800;//10800[frame]==3[minute](60[frame/s])
	int allocInterval_m = 30;
	int objectLinkInterval_m = 10;
	int rootLinkInterval_m = 60;
	int unlinkInterval_m = 1;

	void drawMemory()const;
	void updateObjects();
	void checkState();
	void saveScore();

	Font gameOverFont_m;
	Font gameOverMessageFont_m;
	std::map<String, std::shared_ptr<clickable::Button>> gameOverButtons_m;
	void drawGameOver()const;
	void updateGameOver();
	void initGameOver(gc::Error const &e);

	String message_m;
	void setMessage(String const &s);

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

