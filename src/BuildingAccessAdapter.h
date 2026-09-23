#ifndef BUILDINGACCESSADAPTER_H
#define BUILDINGACCESSADAPTER_H

#include "BuildingAccessInterface.h"
#include "LegacyAccessSystem.h"

class BuildingAccessAdapter : public BuildingAccessInterface, public LegacyAccessSystem {


public:
	void lock();

	void unlock();

	void restrictAccess();
};

#endif
