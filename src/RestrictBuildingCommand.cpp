#include "RestrictBuildingCommand.h"
#include "RestrictedState.h"

void RestrictBuildingCommand::execute() {
	accessSystem->setState(new RestrictedState());
}

RestrictBuildingCommand::RestrictBuildingCommand() : BuildingCommand(){

};

RestrictBuildingCommand::~RestrictBuildingCommand(){

}
