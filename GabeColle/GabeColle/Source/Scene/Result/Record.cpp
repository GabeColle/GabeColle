#include "Record.h"

const String Record::path_m(L"Data/");
Grid<int> Record::rankingData_m(10,4,0);


Record::Record()
{
}

void Record::encryptData(String stageName)
{
	BinaryWriter writer(path_m+stageName+L".bin");
	int array[40];
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 10; ++j){
			array[i * 10 + j] = rankingData_m[i][j];
		}
	}

	const MemoryReader encrypted = Crypto::Encrypt(array, sizeof(array), AES128Key(12, 34, 56, 78));
	writer.write(encrypted.asArray());
}



void Record::decryptData(String stageName)
{
	Array<uint8> sequence;
	String str;
	int array[40];
	BinaryReader reader(path_m+stageName+L".bin");

	if (!reader.isOpened()){
		for (int i = 0; i < 4; ++i){
			for (int j = 0; j < 10; ++j){
				rankingData_m[i][j] = 0;
			}
		}
		return;
	}

	Crypto::Decrypt(reader.readWhole(), array, sizeof(array), AES128Key(12, 34, 56, 78));
	for (int i = 0; i < 4; ++i){
		for (int j = 0; j < 10; ++j){
			rankingData_m[i][j] = array[i * 10 + j];
		}
	}
}