#pragma once

namespace clickable{

class Clickable
{
public:
	Clickable() = default;
	virtual ~Clickable() = default;
	virtual void update() {}
	virtual void draw()const {}
	virtual bool isClicked()const { return false; }
};

}