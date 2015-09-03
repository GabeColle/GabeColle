#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

class Result :
	public SceneManager<String, GameData>::Scene
{
private:
	const Font resultText;
	const String resultSentence = L"Time\nSegmentation Fault\n処理したプロセス\n総合得点";
	const int testTime = 500;
	const int testError = 1000;
	const int testProcess = 50;
	const int testScore = 10000000;
	const String resultValues = Format(testTime,L"\n",testError,L"\n",testProcess,L"\n",testScore);

public:
	Result();
	// クラスの初期化時に一度だけ呼ばれる（省略可）
	void init() override;

	// 毎フレーム updateAndDraw() で呼ばれる
	void update() override;

	// 毎フレーム update() の次に呼ばれる
	void draw() const override;
};