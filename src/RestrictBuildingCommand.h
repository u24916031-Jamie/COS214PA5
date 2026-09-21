#ifndef RESTRICTBUILDINGCOMMAND_H
#define RESTRICTBUILDINGCOMMAND_H

class RestrictBuildingCommand : BuildingCommand {

public:
	BuildingAccessInterface* accessSystem;

	void execute();
};

#endif
