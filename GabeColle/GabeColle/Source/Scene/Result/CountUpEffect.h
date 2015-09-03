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
public:
	CountUpEffect(int countedVariable, int frame);
	void countUp();
	void draw(int x,int y)const;
};