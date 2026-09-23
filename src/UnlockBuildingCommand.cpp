#include "UnlockBuildingCommand.h"
#include "UnlockedState.h"
void UnlockBuildingCommand::execute() {
	accessSystem->setState(new UnlockedState());
}

UnlockBuildingCommand::UnlockBuildingCommand() : BuildingCommand(){

}

UnlockBuildingCommand::~UnlockBuildingCommand(){

}
