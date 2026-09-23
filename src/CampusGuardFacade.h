#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

#include "CampusEmergencyCoordinator.h"
#include "LockBuildingCommand.h"
#include "UnlockBuildingCommand.h"
#include "RestrictBuildingCommand.h"

class CampusGuardFacade {

private:
	CampusEmergencyCoordinator* coordinator;
	LockBuildingCommand* lockCommand;
    UnlockBuildingCommand* unlockCommand;
    RestrictBuildingCommand* restrictCommand;

public:
	CampusGuardFacade( CampusEmergencyCoordinator* coordinator, LockBuildingCommand* lockCommand,
        UnlockBuildingCommand* unlockCommand, RestrictBuildingCommand* restrictCommand);
		
	void coordinateMassEvacuation();

	void coordinateBuildingLockdown();

	void coordinateMedicalResponse();

	void resolveIncident();
};

#endif