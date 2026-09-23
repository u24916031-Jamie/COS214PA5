#include "LockBuildingCommand.h"
#include "LockedState.h"

LockBuildingCommand::LockBuildingCommand(BuildingAccessInterface* accessSystem) : BuildingCommand(accessSystem)
{
}

void LockBuildingCommand::execute()
{
	accessSystem->setState(new LockedState());
}

LockBuildingCommand::~LockBuildingCommand()
{
}
