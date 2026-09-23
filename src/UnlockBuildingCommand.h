#ifndef UNLOCKBUILDINGCOMMAND_H
#define UNLOCKBUILDINGCOMMAND_H

#include "BuildingCommand.h"
#include "BuildingAccessInterface.h"

class UnlockBuildingCommand : public BuildingCommand {

private:
	BuildingAccessInterface *accessSystem;

public:
	void execute() override;
};

#endif
