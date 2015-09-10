#include "BackGroundAnimation.h"

BackGroundAnimation::BackGroundAnimation()
{
	tree[0] = new Array<ExpandCircleEffect>(1, *(new ExpandCircleEffect(Circle(Window::Center(), 60), 30, 0, Palette::Aqua)));
	tree[1] = new Array<ExpandCircleEffect>();
	tree[2] = new Array<ExpandCircleEffect>();
}