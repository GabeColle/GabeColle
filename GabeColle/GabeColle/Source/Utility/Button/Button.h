#pragma once
#include <Siv3D.hpp>

class Button
{
protected:
	int xPos_m;
	int yPos_m;
	int width_m;
	int height_m;
	String str_m;
	Font font_m;
	Color buttonColor_m;
	Color mouseoverButtonColor_m;
	Color textColor_m;
	Color mouseoverTextColor_m;
	Rect rect_m;

public:
	/*
	�f�t�H���g�R���X�g���N�^
	*/
	Button(){}
	/*
	�R���X�g���N�^�@
	����: ���́AX���W�AY���W�A���A�����A�t�H���g�T�C�Y
	*/
	Button(String str , int xPos = 0, int yPos = 0, int width = 100, int height = 50, int fontSize = 30);

	/*
	�R���X�g���N�^�@
	����: ���́AX,Y���W�A�{�^���̃T�C�Y�A�t�H���g�T�C�Y
	*/
	Button(String str , Vec2 pos , Vec2 size = { 100, 50 }, int fontSize = 30);

	/*
	�R���X�g���N�^�@
	����: �t�H���g�T�C�Y�A���́AX���W�AY���W
	*/
	Button(int fontSize, String str, int xPos, int yPos);

	/*
	�R���X�g���N�^�@
	����: �t�H���g�̃T�C�Y�A���́AX,Y���W
	*/
	Button(int fontSize, String str, Vec2 pos);

	/*
	�f�X�g���N�^
	*/
	~Button();

	/*
	�{�^�������N���b�N������true��Ԃ�
	*/
	bool leftClicked();

	/*
	�{�^����`��
	*/
	void draw() const;

	/*
	�{�^���╶���̐F��ς���
	����: �{�^���̐F�A�}�E�X�I�[�o�[���̃{�^���̐F�A�����̐F�A�}�E�X�I�[�o�[���̕����̐F
	*/
	void setColor(Color buttonColor = Palette::Lightgrey, Color mouseoverButtonColor = Palette::Yellowgreen, Color textColor = Palette::Red, Color mouseoverTextColor = Palette::Red);
	
protected:

	/*
	�{�^���̃T�C�Y���e�L�X�g�ɍ��킹��
	*/
	void Button::setRectByFont();

	/*
	�����`�ɍ��W��T�C�Y��K�p
	*/
	void setRect();
};