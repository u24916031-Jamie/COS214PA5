#include "LegacyAccessSystem.h"

LegacyAccessSystem::LegacyAccessSystem(){
	state = FULL_ACCESS;
}

void LegacyAccessSystem::fullAccess() {
	state = FULL_ACCESS;
}

void LegacyAccessSystem::noAccess() {
	state = NO_ACCESS;
}

void LegacyAccessSystem::maintenanceAccess() {
	state = PARTIAL_ACCESS;
}
