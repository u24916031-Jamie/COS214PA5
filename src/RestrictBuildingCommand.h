#ifndef RESTRICTBUILDINGCOMMAND_H
#define RESTRICTBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class RestrictBuildingCommand : public BuildingCommand
{

private:
	BuildingAccessInterface *accessSystem;

public:
	RestrictBuildingCommand(BuildingAccessInterface* accessSystem);
	virtual ~RestrictBuildingCommand();
	void execute() override;
};

#endif
