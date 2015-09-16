#pragma once

#include <Siv3D.hpp>
#include "NodeEffect.h"

class ExtendArrowEffect : public NodeEffect{
private:
	// �o���_
	Vec2 originalPoint_m;
	// �����_
	Vec2 arrivalPoint_m;
	// ���݂̃|�C���g
	Vec2 currentPoint_m;
	// ��󂪐L�т鑬�x
	Vec2 extendVelocity_m;
public:
	ExtendArrowEffect(Line line, int frame_m,int delayFrame_m);
	void update();
	void draw()const;
};