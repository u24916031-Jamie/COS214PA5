#ifndef LOCKBUILDINGCOMMAND_H
#define LOCKBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class LockBuildingCommand : public BuildingCommand {
	
public:
	LockBuildingCommand(BuildingAccessAdapter* accessSystem);
	virtual ~LockBuildingCommand();
	void execute() override;
};

#endif
