#include "LockBuildingCommand.h"
#include "LockedState.h"

LockBuildingCommand::LockBuildingCommand(BuildingAccessAdapter* accessSystem) : BuildingCommand(accessSystem)
{
}

void LockBuildingCommand::execute()
{
	accessSystem->lock();
}

LockBuildingCommand::~LockBuildingCommand()
{
}
