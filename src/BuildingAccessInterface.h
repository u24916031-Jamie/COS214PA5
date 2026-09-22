#ifndef BuildingAccessInterface_H
#define BuildingAccessInterface_H

#include "BuildingState.h"
#include "UnlockedState.h"

class BuildingAccessInterface {

protected:
	BuildingState* state;

public:
BuildingAccessInterface();
	void setState(BuildingState* x);
};

#endif
