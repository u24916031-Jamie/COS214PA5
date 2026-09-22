#include "UnlockBuildingCommand.h"

void UnlockBuildingCommand::execute() {
	accessSystem->unlockBuilding();
}
