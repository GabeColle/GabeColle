#pragma once

#include <Siv3D.hpp>
#include "ExtendArrowEffect.h"
#include "ExpandCircleEffect.h"

class BackGroundAnimation{
private:
	ExtendArrowEffect* arrows[10];
	ExpandCircleEffect* circles[10];
	Array<ExpandCircleEffect>* tree[3];
public:
	BackGroundAnimation();
};