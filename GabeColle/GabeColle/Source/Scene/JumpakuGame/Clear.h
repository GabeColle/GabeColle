#pragma once

#include "JumpakuGame.h"

class JumpakuGame;

class Clear :
	public JumpakuGame::SceneState
{
public:

	void draw()const override;
	void update(JumpakuGame &parent)override;
	Clear();
	~Clear() = default;
};

