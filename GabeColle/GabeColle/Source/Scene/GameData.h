#pragma once

struct GameData
{
	// ステージ名またはステージの番号
	// テスト用データが入っている
	String stageName = L"Stage1";
	// ステージクリアにかかった時間(フレーム数)
	// テスト用データが入っている
	int time = 1024;
	// エラーの数(segmentationFault_m+nullPtrAccess_m+outOfMemory_m+addressOutOfBounds_m)
	// テスト用データが入っている
	int numOfError = 512;
	// 消したオブジェクトの数
	// テスト用データが入っている
	int numOfDeletedObject = 2049;
	// 総合スコア(換算にはtimeとnumOfErrorとnumOfDeletedObjectを使う)
	// テスト用データが入っている
	int totalScore = 4098;
};
