#ifndef BUILDINGCOMMAND_H
#define BUILDINGCOMMAND_H

#include "BuildingAccessAdapter.h"

class BuildingCommand {

protected:
	BuildingAccessAdapter* accessSystem;

public:
	BuildingCommand(BuildingAccessAdapter* accessSystem);
	virtual ~BuildingCommand() = default;
	virtual void execute() = 0;
};

#endif
