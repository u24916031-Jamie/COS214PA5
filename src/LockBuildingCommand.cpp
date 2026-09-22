#include "LockBuildingCommand.h"
#include "LockedState.h"

void LockBuildingCommand::execute() {
	accessSystem->setState(new LockedState());
}
