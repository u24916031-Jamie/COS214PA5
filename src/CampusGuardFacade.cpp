#include "CampusGuardFacade.h"

#include <iostream>

CampusGuardFacade::CampusGuardFacade( SecurityService* securityService, 
	MedicalService* medicalService,CommunicationService* communicationService){

    this->securityService = securityService;
    this->medicalService = medicalService;
    this->communicationService = communicationService;

}

void CampusGuardFacade::coordinateMassEvacuation(){
    std::cout << "\n=== MASS EVACUATION INITIATED ===" << std::endl;

    for (auto i : building){
        i->coordinateBuildingEvacuation();
    }

    securityService->sendUpdate("FireDetected");
}
			
void CampusGuardFacade::coordinateBuildingEvacuation(int index){
    if (index < 0 || index > static_cast<int>(building.size())){
        return;
    }

    building[index]->coordinateBuildingEvacuation();

    securityService->sendUpdate("FireDetected");
}

void CampusGuardFacade::coordinateMassLockdown(){
    std::cout << "\n=== CAMPUS WIDE LOCKDOWN INITIATED ===" << std::endl;

    for (auto i : building){
        i->coordinateBuildingLockdown();
    }

    securityService->sendUpdate("IntruderDetected");
}

void CampusGuardFacade::coordinateBuildingLockdown(int index){
    if (index < 0 || index > static_cast<int>(building.size())){
        return;
    }

    building[index]->coordinateBuildingEvacuation();
    
    securityService->sendUpdate("IntruderDetected");
}

void CampusGuardFacade::coordinateMedicalResponse(int index){
    if (index < 0 || index > static_cast<int>(building.size())){
        return;
    }

    building[index]->coordinateMedicalResponse();

    medicalService->sendUpdate("MedicalEmergency");
}

void CampusGuardFacade::resolveIncident(int index){
    if (index < 0 || index > static_cast<int>(building.size())){
        return;
    }

    building[index]->coordinateResolve();

    communicationService->sendUpdate("AllClear");
}

void CampusGuardFacade::addBuilding(BuildingFacade* building){
    if (building != nullptr){
        this->building.push_back(building);
    }
}