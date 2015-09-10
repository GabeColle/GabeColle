#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include<map>

#include"../GameData.h"
#include"../../GC/Memory.h"
#include"../../Clickable/CircleObject.h"
#include"LinkArrow.h"
#include"../../Clickable/Button.h"
#include"../../Utility/Text.h"

class GameOver;
class Clear;
class Playing;

class Game3 :
	public SceneManager<String, GameData>::Scene
{
	static int const SIZE_m = 51;
	using LinkTable_t = std::array < std::array<LinkArrow, SIZE_m>, SIZE_m >;
	friend GameOver;
	friend Clear;
	friend Playing;
public:
	class SceneState
	{
	protected:
		using Buttons_t = std::map<String, std::shared_ptr<clickable::Button>>;
		Buttons_t buttons_m;
		Effect buttonEffect_m;
		Text title_m;
		Text message_m;
		Color back_m;
		static String const nextScene_m;
	public:
		virtual void draw()const = 0;
		virtual void update(Game3 &parent) = 0;
		virtual ~SceneState() = default;
	};
private:
	gc::Memory<clickable::CircleObject> memory_m;
	int deletes_m = 0;
	LinkTable_t linkArrowTable_m;
	long frame_m = 0;
	Effect objectEffect_m;
protected:
	long const CLEAR_LIMIT_m = 10800;//10800[frame]==3[minute](60[frame/s])
	int allocInterval_m = 30;
	int objectLinkInterval_m = 10;
	int rootLinkInterval_m = 60;
	int unlinkInterval_m = 1;
private:
	void drawMemory()const;
	void updateMemory();
	void checkState();
	void saveScore();

	std::shared_ptr<SceneState> sceneState_m;
public:
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;

	Game3();
	~Game3() = default;
};

