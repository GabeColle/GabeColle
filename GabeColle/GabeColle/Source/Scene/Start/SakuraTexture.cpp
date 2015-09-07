#include"SakuraTexture.h"

SakuraTexture::SakuraTexture()
	:distance_m(1.0 - 0.8 * Random())
{
	static Image const image(L"Asset/Image/SakuraMosaiced.png");
	texture_m = Texture(image.scaled(distance_m, Interpolation::Area));
	
	t0_m = Random(0.0, Math::Pi);
	rect_m = Rect(RandomVec2(1280, 720).asPoint(), texture_m.size);
}

void SakuraTexture::update()
{
	double t = static_cast<double>(frame_m) / 15.0;
	int dx = static_cast<int>(5.0 * sin(t + t0_m) * distance_m);
	int dy = static_cast<int>(0.5 * (sin(t) + t) * distance_m);
	rect_m.moveBy(dx, dy);
	if (rect_m.y >= 720) {
		frame_m = 0;
		t0_m = Random(0.0, Math::Pi);
		rect_m = Rect({ Random(0, 1280), -100 }, texture_m.size);
	}
	++frame_m;
}

void SakuraTexture::draw()const
{
	rect_m(texture_m).draw();
}
