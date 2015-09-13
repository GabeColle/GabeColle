#pragma once

#include <Siv3D.hpp>
#include "../Result/NodeEffect.h"

class DescendAndCountStringEffect : public NodeEffect{
private:
	// �~�Ղ����镶��
	String descendedString_m;
	// �X�^�[�g�ʒu
	int startPos;
	// �s�����x
	int currentTransparency_m;
	// y�����̏グ��
	int increaseYRange_m;
	// �s�����x�̏グ��
	int increaseTransparencyRange_m;
	// �`��p�t�H���g
	Font drawingString_m;
public:
	DescendAndCountStringEffect(String str, int frame, int delayFrame);
	void update();
	void draw()const;
	void draw(Vec2 drawPosition)const;
	void setPosition(Vec2 position);
	void inverseCalculationString(String str,int frame);
};
