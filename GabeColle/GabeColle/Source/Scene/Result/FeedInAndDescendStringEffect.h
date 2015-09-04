#pragma once

#include<Siv3D.hpp>

class FeedInAndDescendStringEffect{
private:
	// �~�Ղ����镶��
	String descendedString_m;
	// ���t���[�������č~�Ղ����邩
	int frame_m;
	// ���݂̃t���[����
	int currentFrame_m;
	// ���݂̈ʒu
	Vec2 currentPosition_m;
	// �`��ʒu
	Vec2 position_m;
	// �s�����x
	int currentTransparency_m;
	// y�����̏グ��
	int increaseYRange_m;
	// �s�����x�̏グ��
	int increaseTransparencyRange_m;
	// �`��p�t�H���g
	const Font font_m;
public:
	FeedInAndDescendStringEffect(String str, int frame, Vec2 position);
	void update();
	void draw();
};