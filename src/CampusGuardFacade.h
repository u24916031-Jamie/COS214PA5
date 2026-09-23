#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

#include "LockBuildingCommand.h"
#include "UnlockBuildingCommand.h"
#include "RestrictBuildingCommand.h"
#include "SecurityService.h"
#include "MedicalService.h"
#include "CommunicationService.h"

class CampusGuardFacade {

private:
	SecurityService* securityService;
	MedicalService* medicalService;
	CommunicationService* communicationService;
	LockBuildingCommand* lockCommand;
    UnlockBuildingCommand* unlockCommand;
    RestrictBuildingCommand* restrictCommand;

public:
	CampusGuardFacade( SecurityService* securityService, 
		MedicalService* medicalService, CommunicationService* communicationService, LockBuildingCommand* lockCommand,
        UnlockBuildingCommand* unlockCommand, RestrictBuildingCommand* restrictCommand);
		
	void coordinateMassEvacuation();

	void coordinateBuildingLockdown();

	void coordinateMedicalResponse();

	void resolveIncident();
};

#endif