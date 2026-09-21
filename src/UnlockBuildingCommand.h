#ifndef UNLOCKBUILDINGCOMMAND_H
#define UNLOCKBUILDINGCOMMAND_H

class UnlockBuildingCommand : BuildingCommand {

public:
	BuildingAccessInterface* accessSystem;

	void execute();
};

#endif
