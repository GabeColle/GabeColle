#pragma once

#include<Siv3D.hpp>

namespace gameselect{

	enum class Difficulty
	{
		easy,
		normal,
		hard,
	};

struct Tag
{
	String buttonName;
	String sceneName;
	String gameName;
	Difficulty difficulty;
};

}
