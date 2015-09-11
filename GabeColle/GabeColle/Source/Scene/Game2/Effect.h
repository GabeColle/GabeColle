#pragma once
#include<Siv3D.hpp>

// サンプルコードをそのままコピペだ～
//
// そのままじゃダメだったよ

struct TextEffect : IEffect
{
	const Font m_font;

	const String str_m;

	const Vec2 m_from;

	TextEffect(const Font& font, String str, const Vec2& from)
		: m_font(font)
		, str_m(str)
		, m_from(from) {}

	bool update(double t) override
	{
		if (t/2 >= 1.0)
		{
			return false;
		}

		const double alpha = 1.0 - t/2;

		//const double h = m_value > 80 ? 0.0 : m_value > 50 ? 20.0 : 60.0;

		m_font(str_m).drawCenter(m_from + Vec2(0, -40 * t), HSV(270).toColorF(alpha));

		return true;
	}
};