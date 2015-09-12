#include "Rule.h"

// �N���X�̏��������Ɉ�x�����Ă΂��i�ȗ��j
void Rule::init()
{
	Graphics::SetBackground({ 143, 255, 239 });
	title = Font(70);
	subtitle = Font(40);
	text = Font(20);
	ruleText1 = L"����̓K�x�[�W�R���N�V����������Q�[���ł�";
	Println(Window::Height());
}

// ���t���[�� updateAndDraw() �ŌĂ΂��
void Rule::update()
{
	player = Circle(Mouse::Pos(),1);
}

// ���t���[�� update() �̎��ɌĂ΂��
void Rule::draw() const
{
	title(L"���[���I").drawCenter({ Window::Width()/2, title.size }, Color(255,0,0));
	text(ruleText1).drawCenter({ Window::Width() / 2, (title.size + text.size) * 2 }, Color(0, 0, 0));
	subtitle(L"����").drawCenter({ Window::Width() / 2, (title.size + text.size + subtitle.size) * 2 }, Color(0, 0, 0));

}