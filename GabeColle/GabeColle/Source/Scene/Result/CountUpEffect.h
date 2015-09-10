#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class CountUpEffect : public NodeEffect{
private:
	// �J�E���g�A�b�v����ϐ�
	int countedVariable_m;
	// �J�E���^�[
	int counter_m;
	// �J�E���^�[�̏オ�蕝
	int countRange_m;
	// �`��p
	Font drawingVariable_m;
public:
	CountUpEffect(int countedVariable, int frame, int delayFrame, Vec2 position);
	void update();
	void draw()const;
};