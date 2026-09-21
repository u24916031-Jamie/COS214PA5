#ifndef BUILDINGACCESSADAPTER_H
#define BUILDINGACCESSADAPTER_H

class BuildingAccessAdapter : BuildingAccessInterface, LegacyAccessSystem {


public:
	void lockBuilding();

	void unlockBuilding();

	void restrictAccess();
};

#endif
