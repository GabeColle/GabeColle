#pragma once

#include<Siv3D.hpp>

namespace start{

class ButtonInterface
{
public:
	ButtonInterface() = default;
	virtual ~ButtonInterface() = default;
	virtual void update() {}
	virtual void draw() {}
	virtual bool isClicked()const { return false; }
};

}