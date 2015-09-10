#include "Record.h"

const String Record::path_m(L"Data/result.dat");
Grid<int> Record::rankingData_m(10,4,0);


Record::Record()
{
}

void Record::encryptData()
{
	TextWriter writer(path_m);
	int array[40];
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 10; ++j){
			array[i * 10 + j] = rankingData_m[i][j];
		}
	}

	const MemoryReader encrypted = Crypto::Encrypt(array, sizeof(array), AES128Key(12, 34, 56, 78));
	writer.write(encrypted.asArray());
}



void Record::decryptData()
{
	Array<uint8> sequence;
	String str;
	int array[40];
	TextReader reader(path_m);

	str = reader.readContents();
	str = str.remove_if([](wchar c){return (c == L'{' ||c == L'}'); });
	for (const auto& elem : str.split(L',')){
		sequence.push_back(Parse<uint8>(elem.trim()));
	}
	
	Crypto::Decrypt(MemoryReader(sequence), array, sizeof(array), AES128Key(12, 34, 56, 78));
	
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 10; ++j){
			rankingData_m[i][j] = array[i * 10 + j];
		}
	}
}