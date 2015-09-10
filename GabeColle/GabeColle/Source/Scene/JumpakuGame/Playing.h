#pragma once

#include "JumpakuGame.h"

class JumpakuGame;

class Playing :
	public JumpakuGame::SceneState
{
public:
	void draw()const override;
	void update(JumpakuGame &parent)override;
};

