#include "Rule.h"

// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
void Rule::init()
{
	Graphics::SetBackground({ 143, 255, 239 });
	title = Font(70);
	subtitle = Font(40);
	text = Font(20);
	for (int i = 0; i < 10; i++){
		cir[i] = Cir(Window::Width()/2,i*Window::Height()/10,30,20);
	}
}

// ���t���[�� updateAndDraw() �ŌĂ΂��
void Rule::update()
{
	for (int i = 0; i < 10; i++){
		if (i % 2){
			cir[i].rightmove();
		}
		else{
			cir[i].leftmove();
		}
		cir[i].draw();
	}

}

// ���t���[�� update() �̎��ɌĂ΂��
void Rule::draw() const
{
	title(L"���[���I").drawCenter({ Window::Width()/2, title.size }, Color(255,0,0));
	text(L"����̓K�x�[�W�R���N�V����������Q�[���ł�").drawCenter({ Window::Width() / 2, (title.size + text.size) * 2 }, Color(0, 0, 0));
	subtitle(L"����").drawCenter({ Window::Width() / 2, (title.size + text.size + subtitle.size) * 2 }, Color(0, 0, 0));

}