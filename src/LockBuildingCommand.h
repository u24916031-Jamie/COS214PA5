#ifndef LOCKBUILDINGCOMMAND_H
#define LOCKBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class LockBuildingCommand : BuildingCommand {

private:
	BuildingAccessInterface *accessSystem;

public:
	void execute() override;
};

#endif
