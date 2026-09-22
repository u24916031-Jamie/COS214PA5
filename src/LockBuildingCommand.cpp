#include "LockBuildingCommand.h"

void LockBuildingCommand::execute() {
	accessSystem->lockBuilding();
}
