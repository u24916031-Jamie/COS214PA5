#ifndef RESTRICTBUILDINGCOMMAND_H
#define RESTRICTBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class RestrictBuildingCommand : BuildingCommand
{

public:
	BuildingAccessInterface *accessSystem;

	void execute() override;
};

#endif
