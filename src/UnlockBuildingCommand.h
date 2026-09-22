#ifndef UNLOCKBUILDINGCOMMAND_H
#define UNLOCKBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class UnlockBuildingCommand : BuildingCommand {

public:
	BuildingAccessInterface* accessSystem;

	void execute();
};

#endif
