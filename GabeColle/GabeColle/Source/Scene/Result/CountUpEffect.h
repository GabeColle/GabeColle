#pragma once

#include<Siv3D.hpp>

class CountUpEffect{
private:
	// �J�E���g�A�b�v����ϐ�
	int countedVariable_m;
	// �J�E���^�[
	int counter_m;
	// �J�E���g�I���܂ł̃t���[����
	int frame_m;
	// �J�E���^�[�̏オ�蕝
	int countRange_m;
	// �`��p
	const Font font;
	// �`��ʒu
	Vec2 position_m;
public:
	CountUpEffect(int countedVariable, int frame,Vec2 position);
	void countUp();
	void draw()const;
};