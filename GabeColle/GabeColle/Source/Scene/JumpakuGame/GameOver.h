#pragma once

#include "JumpakuGame.h"

class JumpakuGame;

class GameOver :
	public JumpakuGame::SceneState
{
public:

	void draw()const override;
	void update(JumpakuGame &parent)override;
	GameOver(String const &message);
	~GameOver() = default;
};

