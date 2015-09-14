#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class ExpandCircleEffect : public NodeEffect{
private:
	// �g��G�t�F�N�g��������~
	Circle expandedCircle_m;
	// �~�̐F
	Color color_m;
	// ���X�̉~�̑傫������g�嗦���t�Z
	double magnificationRate_m;
	// ���݂̊g�嗦
	double currentMagnificationRate_m;
	// �g�嗦�̏グ��
	double increaseRange_m;
public:
	ExpandCircleEffect(Circle c, int frame, int delayFrame, Color color);
	void update();
	void draw()const;
};