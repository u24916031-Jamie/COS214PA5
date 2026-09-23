#ifndef UNLOCKBUILDINGCOMMAND_H
#define UNLOCKBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class UnlockBuildingCommand : public BuildingCommand {

private:
	BuildingAccessInterface *accessSystem;

public:
	UnlockBuildingCommand();
	virtual ~UnlockBuildingCommand();
	void execute() override;
};

#endif
