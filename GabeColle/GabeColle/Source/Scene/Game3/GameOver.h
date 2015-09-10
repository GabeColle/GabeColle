#pragma once

#include "Game3.h"

class Game3;

class GameOver :
	public Game3::SceneState
{
public:
	void draw()const override;
	void update(Game3 &parent)override;
	GameOver(String const &message);
	~GameOver() = default;
};

