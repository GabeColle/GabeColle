#pragma once

#include <Siv3D.hpp>
#include "../Result/Effect/NodeEffect.h"

class DescendAndCountStringEffect : public NodeEffect{
private:
	// �{���̕���
	String realString_m;
	// �~�Ղ����镶��
	String descendedString_m;
	// �X�^�[�g�ʒu
	int startPos_m;
	// �s�����x
	int currentTransparency_m;
	// y�����̏グ��
	int increaseYRange_m;
	// �s�����x�̏グ��
	int increaseTransparencyRange_m;
	// �`��p�t�H���g
	Font drawingString_m;
	int stringCountFrame_m;
public:
	DescendAndCountStringEffect(String str, int frame, int delayFrame);
	void update();
	void draw()const;
	void draw(Vec2 realPosition)const;
	void setPosition(Vec2 position);
	String inverseCalculationString(String str,int frame);
	String incrementString(String str);
};
