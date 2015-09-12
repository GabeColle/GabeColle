#pragma once


#include <Siv3D.hpp>


class OutOfEffect : public IEffect
{
private:
	const Font& font_m;
public:
	OutOfEffect(const Font& font);
public:
	bool update(double t) override;
};

