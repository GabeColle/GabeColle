#pragma once

#include"ClickableBase.h"
#include"../GC/Object.h"

namespace clickable{

class CircleObject :
	public ClickableBase<Circle>, gc::Object
{
	enum ObjectState
	{
		ALLOCED,
		FREED,
		EXISTS,
		EXPAIRED,
	};
	ObjectState objectState_m = EXPAIRED;
	int objectFrame_m = 0;
	void changeOobjectState();

	static String const FONT_ASSET_NAME;
	
	String soundName_m;
	
	void drawPressed(Circle shape, String const &text, int frame)const override;
	void drawOver(Circle shape, String const &text, int frame)const override;
	void drawLeft(Circle shape, String const &text, int frame)const override;
	void drawClicked(Circle shape, String const &text, int frame)const override;
public:
	void draw()const;
	void update();
	void alloc(int address);
	void free();
	CircleObject();
	~CircleObject() = default;
};

}
