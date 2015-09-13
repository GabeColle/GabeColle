#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class FadeInAndDescendStringEffect : public NodeEffect{
private:
	// �~�Ղ����镶��
	String descendedString_m;
	// ���݂̈ʒu
	Vec2 currentPosition_m;
	// �s�����x
	int currentTransparency_m;
	// y�����̏グ��
	int increaseYRange_m;
	// �s�����x�̏グ��
	int increaseTransparencyRange_m;
	// �`��p�t�H���g
	Font drawingString_m;
public:
	FadeInAndDescendStringEffect(String str, int frame, int delayFrame, Vec2 position);
	void update();
	void draw()const;
};