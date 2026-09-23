#ifndef BUILDINGCOMMAND_H
#define BUILDINGCOMMAND_H

#include "BuildingAccessInterface.h"

class BuildingCommand {

protected:
	BuildingAccessInterface* accessSystem;

public:
	BuildingCommand(BuildingAccessInterface* accessSystem);
	virtual ~BuildingCommand() = default;
	virtual void execute() = 0;
};

#endif
