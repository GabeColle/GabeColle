#pragma once

struct GameData
{
	// ステージクリアにかかった時間(フレーム数)
	int time;
	// エラーの数(segmentationFault_m+nullPtrAccess_m+outOfMemory_m+addressOutOfBounds_m)
	int numOfError;
	// 消したオブジェクトの数
	int numOfDeletedObject;
	// 総合スコア(換算にはtimeとnumOfErrorとnumOfDeletedObjectを使う)
	int totalScore;
};
