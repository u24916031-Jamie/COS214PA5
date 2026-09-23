#ifndef BUILDINGCOMMAND_H
#define BUILDINGCOMMAND_H

class BuildingCommand {

public:
	BuildingCommand();
	virtual ~BuildingCommand() = 0;
	virtual void execute() = 0;
};

#endif
