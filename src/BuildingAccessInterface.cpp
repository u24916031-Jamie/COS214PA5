#include "BuildingAccessInterface.h"

BuildingAccessInterface::BuildingAccessInterface(){
	state = new UnlockedState();
}

void BuildingAccessInterface::unlockBuilding() {
	delete state;
	state = new UnlockedState();
}

void BuildingAccessInterface::lockBuilding() {
	delete state;
	state = new LockedState();
}

void BuildingAccessInterface::restrictAccess() {
	delete state;
	state = new RestrictedState();
}
