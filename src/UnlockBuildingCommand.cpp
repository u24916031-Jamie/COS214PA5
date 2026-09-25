#include "UnlockBuildingCommand.h"
#include "UnlockedState.h"

void UnlockBuildingCommand::execute() {
	accessSystem->unlock();
}

UnlockBuildingCommand::UnlockBuildingCommand(BuildingAccessAdapter* accessSystem) : BuildingCommand(accessSystem){

}

UnlockBuildingCommand::~UnlockBuildingCommand(){

}

