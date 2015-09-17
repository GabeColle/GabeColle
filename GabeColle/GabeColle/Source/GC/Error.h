#pragma once 

namespace gc {


/**
*様々なエラーの数を記憶する
*/
class Error
{
public:
	Error() = default;
	Error(int s, int n, int o, int a)
		:segmentationFault_m(s),
		nullptrAccess_m(n),
		outOfMemory_m(o),
		addressOutOfBounds_m(a)
	{}
	/**生成してないオブジェクトへのアクセス*/
	int segmentationFault_m = 0;
	/**ヌルポインタへのアクセス*/
	int nullptrAccess_m = 0;
	/**メモリ不足でオブジェクトを生成できない*/
	int outOfMemory_m = 0;
	/**アドレスがメモリの範囲外*/
	int addressOutOfBounds_m = 0;
};

}