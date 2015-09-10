#pragma once


#include <Siv3D.hpp>


class FadeOutEffect : public IEffect
{
public:
	Font font_m;
	Vec2 pos_m;
	String str_m;
public:
	FadeOutEffect() = default;
	FadeOutEffect(Font font, String str, Vec2 pos);
public:
	bool update(double t) override;
};

