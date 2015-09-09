#include "Record.h"

const String Record::path_m(L"Data/result.csv");
Grid<int> Record::rankingData_m(10,4,0);
MemoryReader Record::encrypted;


Record::Record()
{
}

void Record::encryptCSV()
{
	TextWriter writer(path_m);
	int array[40];
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 10; ++j){
			array[i * 10 + j] = rankingData_m[i][j];
			Print(array[i * 10 + j]);
			Print(L",");
			
		}
	}

	encrypted = Crypto::Encrypt(array, sizeof(array), AES128Key(12, 34, 56, 78));
	writer.write(encrypted.asArray());
}



void Record::decryptCSV()
{
	Array<uint8> suretsu;
	String str;
	TextReader reader(path_m);
	str = reader.readContents();
	str = str.remove(L'{');
	str = str.remove(L'}');
	for (const auto& elem : str.split(L',')){
		suretsu.push_back(Parse<uint8>(elem.trim()));
	}
	int array[40];
	

	Crypto::Decrypt(MemoryReader(suretsu), array, sizeof(array), AES128Key(12, 34, 56, 78));
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 10; ++j){
			rankingData_m[i][j] = array[i * 10 + j];
			Print(array[i * 10 + j]);
			Print(L",");
		}
	}
}