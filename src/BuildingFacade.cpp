#include "BuildingFacade.h"

#include <iostream>

BuildingFacade::BuildingFacade(std::string name, BuildingAccessAdapter* accessSystem, LockBuildingCommand* lockCommand,
    UnlockBuildingCommand* unlockCommand, RestrictBuildingCommand* restrictCommand){
    this->name = name;
    this->accessSystem = accessSystem;
    this->lockCommand = lockCommand;
    this->unlockCommand = unlockCommand;
    this->restrictCommand = restrictCommand;
}

void BuildingFacade::coordinateBuildingEvacuation(){
    std::cout << "\n=== "<<this->name<<" BUILDING EVACUATION INITIATED ===" << std::endl;

    restrictCommand->execute();
}

void BuildingFacade::coordinateBuildingLockdown(){
    std::cout << "\n=== "<<this->name<<" BUILDING LOCKDOWN INITIATED ===" << std::endl;

    lockCommand->execute();
}

void BuildingFacade::coordinateMedicalResponse(){
    std::cout << "\n=== MEDICAL RESPONSE INITIATED FOR "<<this->name<<" ===" << std::endl;

}

void BuildingFacade::coordinateResolve(){
    std::cout << "\n=== "<<this->name<<" BUILDING IS UNLOCKED NOW ===" << std::endl;

    unlockCommand->execute();
}

bool BuildingFacade::allowStaffAccess(Staff* user){
    return accessSystem->enter(user);
}
