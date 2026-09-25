#ifndef RESTRICTBUILDINGCOMMAND_H
#define RESTRICTBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class RestrictBuildingCommand : public BuildingCommand
{

public:
	RestrictBuildingCommand(BuildingAccessAdapter* accessSystem);
	virtual ~RestrictBuildingCommand();
	void execute() override;
};

#endif
