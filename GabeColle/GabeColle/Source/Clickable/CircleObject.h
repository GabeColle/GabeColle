#pragma once

#include"ClickableBase.h"
#include"../GC/Object.h"

namespace clickable{

class CircleObject :
	public ClickableBase<Circle>, public gc::Object
{
	static String const fontAsset_m;
	static String const newSound_m;
	static String const deleteSound_m;
	
	void drawPressed(Circle shape, String const &text, int frame)const override;
	void drawOver(Circle shape, String const &text, int frame)const override;
	void drawLeft(Circle shape, String const &text, int frame)const override;
	void drawClicked(Circle shape, String const &text, int frame)const override;
public:
	void update() override;
	bool isClicked()const override;
	void initialize(int address, Effect &effect);
	Vec2 center()const;
	void finalize(Effect &effect);
	CircleObject();
	~CircleObject() = default;
};

}
