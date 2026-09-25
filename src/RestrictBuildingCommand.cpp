#include "RestrictBuildingCommand.h"
#include "RestrictedState.h"

void RestrictBuildingCommand::execute() {
	accessSystem->restrictAccess();
}

RestrictBuildingCommand::RestrictBuildingCommand(BuildingAccessAdapter* accessSystem) : BuildingCommand(accessSystem){

};

RestrictBuildingCommand::~RestrictBuildingCommand(){

}
