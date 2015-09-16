#pragma once

#include "Game3.h"

class Game3;

class Clear :
	public Game3::SceneState
{
public:
	Clear();
	void draw()const override;
	void update(Game3 &parent)override;
	~Clear() = default;
};

