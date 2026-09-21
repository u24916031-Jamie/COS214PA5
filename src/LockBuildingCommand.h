#ifndef LOCKBUILDINGCOMMAND_H
#define LOCKBUILDINGCOMMAND_H

class LockBuildingCommand : BuildingCommand {

public:
	BuildingAccessInterface* accessSystem;

	void execute();
};

#endif
