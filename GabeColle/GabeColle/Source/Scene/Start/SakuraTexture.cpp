#include "SakuraTexture.h"

SakuraTexture::SakuraTexture()
	:distance_m(1.0 - 0.8 * Random())
{
	static const Image image = Image(L"Asset/Image/SakuraMosaiced.png");
	texture_m = Texture(image.scaled(distance_m, Interpolation::Area));
}

void SakuraTexture::update()
{

}

void SakuraTexture::draw()const
{
	texture_m.draw();
}