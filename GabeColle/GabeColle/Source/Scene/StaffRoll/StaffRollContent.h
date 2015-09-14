#pragma once

#include <siv3D.hpp>
#include "MemoryWrapper.h"
#include "MemoryFromRoot.h"
#include "DespiteOfScene.h"

class StaffRollContent
{
private:
	static const String titleFontHandle;
	static const int INIT_OBJECTS;
	Texture circleLogo;
	Texture titleLogo;
	staffroll::MemoryWrapper memory_m;
	std::shared_ptr<staffroll::MemoryFromRoot> memoryR_m;
	Array<String> parties_m;
	String state_m;
	
public:
	StaffRollContent( String contentName_m,Array<String> parties);
	StaffRollContent(String contentName_m);
	void init();
	void update();
	void draw()const;
};