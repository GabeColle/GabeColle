#pragma once

#include<siv3D.hpp>

class SakuraTexture
{
	Rect rect_m;
	Texture texture_m;
	double distance_m;
	int frame_m = 0;
	double t0_m = 0;
public:
	SakuraTexture();
	void update();
	void draw()const;
};

