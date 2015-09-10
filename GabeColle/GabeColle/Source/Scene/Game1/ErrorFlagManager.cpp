#include "ErrorFlagManager.h"


ErrorFlagManager::ErrorFlagManager() : prevError(), nowError()
{
}


void ErrorFlagManager::update(gc::Error error)
{
	prevError = nowError;
	nowError = error;
	flags.addressOutOfBounds_m  = prevError.addressOutOfBounds_m != nowError.addressOutOfBounds_m;
	flags.nullptrAccess_m = prevError.nullptrAccess_m != nowError.nullptrAccess_m;
	flags.outOfMemory_m = prevError.outOfMemory_m != nowError.outOfMemory_m;
	flags.segmentationFault_m = prevError.segmentationFault_m != nowError.segmentationFault_m;
}

ErrorFlag ErrorFlagManager::getErrorFlag() const
{
	return flags;
}