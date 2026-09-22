#include "RestrictBuildingCommand.h"

void RestrictBuildingCommand::execute() {
	accessSystem->restrictAccess();
}
