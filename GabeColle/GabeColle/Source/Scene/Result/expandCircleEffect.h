#pragma once

#include<Siv3D.hpp>

class ExpandCircleEffect{
private:
	// �g��G�t�F�N�g��������~
	Circle expandedCircle_m;
	// �g��ɂ����鎞��
	int frame_m;
	// �G�t�F�N�g�K�p�܂ł̎���
	int delayFrame_m;
	// �~�̐F
	Color color_m;
	// ���X�̉~�̑傫������g�嗦���t�Z
	double magnificationRate_m;
	// ���݂̊g�嗦
	double currentMagnificationRate_m;
	// �g�嗦�̏グ��
	double increaseRange_m;
	// ���݂̃t���[��(delayFrame�J�E���^)
	int currentFrame_m;
public:
	ExpandCircleEffect(Circle c, int frame, int delayFrame, Color color);
	void update();
	void draw()const;
};