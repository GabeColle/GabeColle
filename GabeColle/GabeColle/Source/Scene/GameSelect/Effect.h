#pragma once
#include<Siv3D.hpp>

struct LineEffect : IEffect
{
	const LineString m_line;
	Color m_color;

	LineEffect(LineString line,Color color)
		: m_line(line),
		m_color(color)
		{}

	bool update(double t) override
	{
		if (t >= 1.0)
		{
			return false;
		}

		const double alpha = 1.0 - t;


		m_line.draw(1.0, HSV(m_color).toColorF(alpha));

		return true;
	}
};


struct LingEffect : IEffect
{
	Color m_color;
	Vec2 m_pos;
	int m_r;

	LingEffect(Vec2 pos, int r, Color color)
		: m_pos(pos),
		m_color(color)
	{
		m_r = r;
	}

	bool update(double t) override
	{
		if (t >= 1.0)
		{
			return false;
		}

		const double alpha = 1.0 - t;

		Circle(m_pos, m_r * t).drawFrame(1.0, 1.0, HSV(m_color).toColorF(alpha));

		return true;
	}
};