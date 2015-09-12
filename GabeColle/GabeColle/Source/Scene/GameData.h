#pragma once

struct GameData
{
	// ステージ名またはステージの番号
	// テスト用データが入っている
	String stageName = L"\0";
	// ステージクリアにかかった時間(フレーム数)
	// テスト用データが入っている
	int time = 0;
	// エラーの数(segmentationFault_m+nullPtrAccess_m+outOfMemory_m+addressOutOfBounds_m)
	// テスト用データが入っている
	int numOfError = 0;
	// 消したオブジェクトの数
	// テスト用データが入っている
	int numOfDeletedObject = 0;
	// 総合スコア(換算にはtimeとnumOfErrorとnumOfDeletedObjectを使う)
	// テスト用データが入っている
	int totalScore = 0;
};
