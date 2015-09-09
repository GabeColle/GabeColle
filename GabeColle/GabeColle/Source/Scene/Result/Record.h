#pragma once

#include <Siv3D.hpp>

class Record{
private:
	static const String path_m;
	static MemoryReader encrypted;
public:
	static Grid<int> rankingData_m;

	Record();
	static void encryptCSV();
	static void decryptCSV();

};