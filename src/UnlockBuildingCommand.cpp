#include "UnlockBuildingCommand.h"
#include "UnlockedState.h"
void UnlockBuildingCommand::execute() {
	accessSystem->setState(new UnlockedState());
}

UnlockBuildingCommand::UnlockBuildingCommand(BuildingAccessInterface* accessSystem) : BuildingCommand(accessSystem){

}

UnlockBuildingCommand::~UnlockBuildingCommand(){

}
