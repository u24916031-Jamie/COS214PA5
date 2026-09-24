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
			
void CampusGuardFacade::coordinateBuildingEvacuation(BuildingFacade* building){
    if (building==nullptr){
        return;
    }
    
    building->coordinateBuildingEvacuation();

    securityService->sendUpdate("FireDetected");
}

void CampusGuardFacade::coordinateMassLockdown(){
    std::cout << "\n=== CAMPUS WIDE LOCKDOWN INITIATED ===" << std::endl;

    for (auto i : building){
        i->coordinateBuildingLockdown();
    }

    securityService->sendUpdate("IntruderDetected");
}

void CampusGuardFacade::coordinateBuildingLockdown(BuildingFacade* building){
    if (building==nullptr){
        return;
    }
    
    building->coordinateBuildingEvacuation();
    
    securityService->sendUpdate("IntruderDetected");
}

void CampusGuardFacade::coordinateMedicalResponse(BuildingFacade* building){
    if (building==nullptr){     
        return;
    }
    
    building->coordinateMedicalResponse();

    medicalService->sendUpdate("MedicalEmergency");
}

void CampusGuardFacade::resolveIncident(BuildingFacade* building){
    if (building==nullptr){ 
        for (auto i : this->building){
            i->coordinateResolve();
        }        
        return;
    }
    
    building->coordinateResolve();

    communicationService->sendUpdate("AllClear");
}

void CampusGuardFacade::resolveMassIncident(){
    for (auto i : building){
        i->coordinateResolve();
    }

    communicationService->sendUpdate("AllClear");
}

void CampusGuardFacade::addBuilding(BuildingFacade* building){
    if (building != nullptr){
        this->building.push_back(building);
    }
}