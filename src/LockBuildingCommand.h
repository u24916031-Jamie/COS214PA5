#ifndef LOCKBUILDINGCOMMAND_H
#define LOCKBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class LockBuildingCommand : BuildingCommand {

public:
	BuildingAccessInterface* accessSystem;

	void execute();
};

#endif
