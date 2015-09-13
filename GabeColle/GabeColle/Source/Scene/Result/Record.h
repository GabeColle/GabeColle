#pragma once

#include <Siv3D.hpp>

class Record{
private:
	static const String path_m;
public:
	static Grid<int> rankingData_m;

	Record();
	static void encryptData(String stageName);
	static void decryptData(String stageName);
};