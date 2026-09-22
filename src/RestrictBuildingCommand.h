#ifndef RESTRICTBUILDINGCOMMAND_H
#define RESTRICTBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class RestrictBuildingCommand : BuildingCommand
{

private:
	BuildingAccessInterface *accessSystem;

public:
	void execute() override;
};

#endif
