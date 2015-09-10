#pragma once
#include"Game2.h"

class Game2Hard
	: public Game2
{
public:
	Game2Hard() : Game2(){
		NUM_OF_MEMORY = 18;
		name_m = L"Game2(Hard)";
	};
};