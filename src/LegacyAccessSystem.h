#ifndef LegacyAccessSystem_H
#define LegacyAccessSystem_H

#include "LockedState.h"
#include "UnlockedState.h"
#include "RestrictedState.h"

enum Bstate {NO_ACCESS, FULL_ACCESS, PARTIAL_ACCESS};

class LegacyAccessSystem
{
protected:
	Bstate state;

public:
	LegacyAccessSystem();

	void fullAccess();

	void noAccess();

	void maintenanceAccess();
};

#endif
