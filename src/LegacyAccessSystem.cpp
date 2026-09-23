#include "LegacyAccessSystem.h"

LegacyAccessSystem::LegacyAccessSystem(){
	buildingState = FULL_ACCESS;
}

void LegacyAccessSystem::fullAccess() {
	buildingState = FULL_ACCESS;
}

void LegacyAccessSystem::noAccess() {
	buildingState = NO_ACCESS;
}

void LegacyAccessSystem::maintenanceAccess() {
	buildingState = PARTIAL_ACCESS;
}

LegacyAccessSystem::~LegacyAccessSystem(){

}
