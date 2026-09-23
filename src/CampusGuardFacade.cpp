#include "CampusGuardFacade.h"

#include <iostream>

CampusGuardFacade::CampusGuardFacade(CampusEmergencyCoordinator* coordinator, LockBuildingCommand* lockCommand,
    UnlockBuildingCommand* unlockCommand, RestrictBuildingCommand* restrictCommand){

    this->coordinator = coordinator;
    this->lockCommand = lockCommand;
    this->unlockCommand = unlockCommand;
    this->restrictCommand = restrictCommand;
}

void CampusGuardFacade::coordinateMassEvacuation(){
    std::cout << "\n=== MASS EVACUATION INITIATED ===" << std::endl;

    restrictCommand->execute();

    coordinator->notify(nullptr, "FireDetected");
}

void CampusGuardFacade::coordinateBuildingLockdown(){
    std::cout << "\n=== BUILDING LOCKDOWN INITIATED ===" << std::endl;

    lockCommand->execute();

    coordinator->notify( nullptr, "IntruderDetected");
}

void CampusGuardFacade::coordinateMedicalResponse(){
    std::cout << "\n=== MEDICAL RESPONSE INITIATED ===" << std::endl;

    coordinator->notify(nullptr, "MedicalEmergency");
}

void CampusGuardFacade::resolveIncident(){
    std::cout << "\n=== INCIDENT RESOLVED ===" << std::endl;

    unlockCommand->execute();

    coordinator->notify(nullptr, "AllClear");
}
