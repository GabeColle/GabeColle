#include "Sample.h"

// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
void Sample::init()
{
	texture_m = Texture(L"Asset/Image/GabeColle.png");
}

// ���t���[�� updateAndDraw() �ŌĂ΂��
void Sample::update()
{

}

// ���t���[�� update() �̎��ɌĂ΂��
void Sample::draw() const
{
	texture_m.drawAt(Window::Center());
}