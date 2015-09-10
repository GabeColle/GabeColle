#pragma once

#include <Siv3D.hpp>
#include "ExtendArrowEffect.h"
#include "ExpandCircleEffect.h"

class BackGroundAnimation{
private:
	Sound BGM_m;
	Texture texture_m; // resultBG2 ’˜ŽÒ:/\lex
	int BGVelocity_m;
	int bg_x_m;
	int bg_x2_m;

	ExtendArrowEffect* arrows[10];
	ExpandCircleEffect* circles[10];
	Array<ExpandCircleEffect>* tree[3];
public:
	BackGroundAnimation();
	void update();
	void draw()const;
};