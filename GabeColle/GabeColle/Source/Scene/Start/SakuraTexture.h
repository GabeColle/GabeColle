#pragma once

#include<siv3D.hpp>

class SakuraTexture
{
	Texture texture_m;
	double distance_m;
public:
	SakuraTexture();
	void update();
	void draw()const;
};

