#ifndef BUILDINGACCESSINTERFACE_H
#define BUILDINGACCESSINTERFACE_H

#include "LockedState.h"
#include "UnlockedState.h"
#include "RestrictedState.h"

class BuildingAccessInterface
{
private:
	BuildingState *state;

public:
	BuildingAccessInterface();

	void unlockBuilding();

	void lockBuilding();

	void restrictAccess();
};

#endif
