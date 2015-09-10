#pragma once


#include <Siv3D.hpp>
#include "../../GC/Error.h"


struct ErrorFlag
{
	bool segmentationFault_m = false;
	bool nullptrAccess_m = false;
	bool outOfMemory_m = false;
	bool addressOutOfBounds_m = false;
};

class ErrorFlagManager
{
private:
	gc::Error prevError;
	gc::Error nowError;
	ErrorFlag flags;
public:
	ErrorFlagManager();
public:
	void update(gc::Error error);
	ErrorFlag getErrorFlag() const;
};

