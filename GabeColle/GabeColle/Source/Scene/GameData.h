#pragma once

struct GameData
{
	// ステージクリアにかかった時間(フレーム数)
	// テスト用データが入っている
	int time = 1024;
	// エラーの数(segmentationFault_m+nullPtrAccess_m+outOfMemory_m+addressOutOfBounds_m)
	// テスト用データが入っている
	int numOfError = 512;
	// 消したオブジェクトの数
	// テスト用データが入っている
	int numOfDeletedObject = 2049;
	// テスト用データが入っている
	// 総合スコア(換算にはtimeとnumOfErrorとnumOfDeletedObjectを使う)
	int totalScore = 4098;
};
