#include "LockBuildingCommand.h"
#include "LockedState.h"

LockBuildingCommand::LockBuildingCommand() : BuildingCommand()
{
}

void LockBuildingCommand::execute()
{
	accessSystem->setState(new LockedState());
}

LockBuildingCommand::~LockBuildingCommand()
{
}
