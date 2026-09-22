#include "BuildingAccessAdapter.h"

void BuildingAccessAdapter::lock() {
	this->setState(new LockedState());
	this->noAccess();
}

void BuildingAccessAdapter::unlock() {
	this->setState(new UnlockedState());
	this->fullAccess();
}

void BuildingAccessAdapter::restrictAccess() {
	this->setState(new RestrictedState());
	this->maintenanceAccess();
}
