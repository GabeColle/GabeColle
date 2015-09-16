#pragma once
#include"Game2.h"

class Game2Easy
	: public Game2
{
public:
	Game2Easy() : Game2(){
		NUM_OF_MEMORY = 6;
		name_m = L"Game2(Easy)";
	};
};