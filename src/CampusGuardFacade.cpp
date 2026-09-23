#include "CampusGuardFacade.h"

#include <iostream>

CampusGuardFacade::CampusGuardFacade( SecurityService* securityService, 
	MedicalService* medicalService,CommunicationService* communicationService, LockBuildingCommand* lockCommand,
    UnlockBuildingCommand* unlockCommand, RestrictBuildingCommand* restrictCommand){

    this->securityService = securityService;
    this->medicalService = medicalService;
    this->communicationService = communicationService;
    this->lockCommand = lockCommand;
    this->unlockCommand = unlockCommand;
    this->restrictCommand = restrictCommand;
}

void CampusGuardFacade::coordinateMassEvacuation(){
    std::cout << "\n=== MASS EVACUATION INITIATED ===" << std::endl;

    restrictCommand->execute();

    securityService->sendUpdate("FireDetected");
}

void CampusGuardFacade::coordinateBuildingLockdown(){
    std::cout << "\n=== BUILDING LOCKDOWN INITIATED ===" << std::endl;

    lockCommand->execute();

    securityService->sendUpdate("IntruderDetected");
}

void CampusGuardFacade::coordinateMedicalResponse(){
    std::cout << "\n=== MEDICAL RESPONSE INITIATED ===" << std::endl;

    medicalService->sendUpdate("MedicalEmergency");
}

void CampusGuardFacade::resolveIncident(){
    std::cout << "\n=== INCIDENT RESOLVED ===" << std::endl;

    unlockCommand->execute();

    communicationService->sendUpdate("AllClear");
}
