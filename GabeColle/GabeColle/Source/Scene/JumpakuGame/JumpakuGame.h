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
	JumpakuGame();
	void drawMemory(gc::Memory<clickable::CircleObject> const &memory)
	{
		static Font font;
		font.drawCenter(L"Root", Circle(memory.root().center(), 50.0).draw(Palette::Aqua).center);

		//オブジェクトを描く
		auto drawCircle = [&memory] (int address)
		{
			double const r = 40.0;
			if (!memory.hasExpired(address)) {
				Circle c = Circle(memory.access(address).center(), r);
				if (c.mouseOver) {
					c.draw(Color(Palette::Pink, 128)).drawFrame(0.0, 3.0, Palette::Red);
				}
				else {
					c.draw(Color(Palette::Red, 128)).drawFrame(0.0, 3.0, Palette::Darkred);
				}
				font.drawCenter(ToString(address), c.center);
			}
		};
		for (int i(1); i < memory.size(); ++i) {
			drawCircle(i);
		}

		//ルートからの参照を描く
		auto rm = memory.getRelation();
		for (int j(1); j < memory.size(); ++j) {
			if (rm.areLinked(0, j)) {
				Line(memory.root().center(), memory.access(j).center()).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
			}
			else if (rm.areLinked(j, 0)) {
				Line(memory.access(j).center(), memory.root().center()).drawArrow(4, { 20, 50 }, Color(Palette::Yellow, 128));
			}
		}

		//オブジェクト同士の参照を描く
		auto drawArrow = [&memory] (int i, int j)
		{
			auto const &relation = memory.getRelation();
			if (relation.areLinked(i, j)) {
				Vec2 const &iCenter = memory.access(i).center();
				Vec2 const &jCenter = memory.access(j).center();
				static Color const clr = Color(Palette::Yellow, 128);
				if (i == j) {
					Circle(Vec2(40.0, -40.0).movedBy(iCenter), 40.0).drawArc(-Math::Pi / 2.0, 3.0 / 2.0 * Math::Pi, 2.0, 2.0, clr);
					Line(Vec2(0.0, -40.0).movedBy(iCenter), iCenter).drawArrow(4, { 20, 50 }, clr);
					Line(Vec2(40.0, 0.0).movedBy(iCenter), iCenter).draw(4, clr);
				}
				else {
					Line(iCenter, jCenter).drawArrow(4, { 20, 50 }, clr);
				}
			}
		};
		for (int i(1); i < memory.size(); ++i) {
			for (int j(1); j < memory.size(); ++j) {
				drawArrow(i, j);
			}
		}
	}

public:
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override
	{
		memory_m.root().alloc(0);
	}

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override
	{
	}

	// 毎フレーム update() の次に呼ばれる
	void draw() const override
	{
		drawMemory(memory_m);
	}
	JumpakuGame();
	~JumpakuGame() = default;
};

