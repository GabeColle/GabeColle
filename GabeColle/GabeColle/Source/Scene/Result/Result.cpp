#include "Result.h"

Result::Result() : resultText(25)
{

}

// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
void Result::init()
{
}

// ���t���[�� updateAndDraw() �ŌĂ΂��
void Result::update()
{

}

// ���t���[�� update() �̎��ɌĂ΂��
void Result::draw() const
{
	resultText(resultSentence).draw(0,0,Palette::White,2.2);
	resultText(resultValues).draw(0, 50, Palette::Tomato, 2.2);
	
}