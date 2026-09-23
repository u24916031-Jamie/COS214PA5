#ifndef UNLOCKBUILDINGCOMMAND_H
#define UNLOCKBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class UnlockBuildingCommand : public BuildingCommand {

public:
	UnlockBuildingCommand(BuildingAccessInterface* accessSystem);
	virtual ~UnlockBuildingCommand();
	void execute() override;
};

#endif
