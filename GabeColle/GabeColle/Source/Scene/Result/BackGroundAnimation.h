#pragma once

#include <Siv3D.hpp>
#include "Effect/ExtendArrowEffect.h"
#include "Effect/ExpandCircleEffect.h"

class BackGroundAnimation{
private:
	Sound BGM_m;
	Texture texture_m; // resultBG2 ’˜ŽÒ:/\lex
	int BGVelocity_m;
	int bg_x_m;
	int bg_x2_m;

public:
	BackGroundAnimation();
	void update();
	void draw()const;
};