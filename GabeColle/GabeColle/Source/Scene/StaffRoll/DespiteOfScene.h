#pragma once

#include <Siv3D.hpp>

class DespiteOfScene{
private:
	
	static String titleLogo;
public:
	static bool isDrawingState_m;
	static void init();
	static void sendDrawingInstruction();
	static void sendNotDrawingInstruction();
	static void draw();
};