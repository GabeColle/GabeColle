#pragma once

#include<Siv3D.hpp>
#include<HamFramework.hpp>

#include"../GameData.h"

class Result :
	public SceneManager<String, GameData>::Scene
{
private:
	const Font resultText;
	const String resultSentence = L"Time\nSegmentation Fault\n���������v���Z�X\n�������_";
	const int testTime = 500;
	const int testError = 1000;
	const int testProcess = 50;
	const int testScore = 10000000;
	const String resultValues = Format(testTime,L"\n",testError,L"\n",testProcess,L"\n",testScore);

public:
	Result();
	// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
	void init() override;

	// ���t���[�� updateAndDraw() �ŌĂ΂��
	void update() override;

	// ���t���[�� update() �̎��ɌĂ΂��
	void draw() const override;
};