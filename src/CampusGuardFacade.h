#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

#include "BuildingFacade.h"
#include "SecurityService.h"
#include "MedicalService.h"
#include "CommunicationService.h"
#include <vector>

class CampusGuardFacade {

private:
	SecurityService* securityService;
	MedicalService* medicalService;
	CommunicationService* communicationService;
	std::vector<BuildingFacade*> building;

public:
	CampusGuardFacade( SecurityService* securityService, 
		MedicalService* medicalService, CommunicationService* communicationService);
		
	void coordinateMassEvacuation();			//evacuates every building
	void coordinateBuildingEvacuation(int index);	//evacuates specific building

	void coordinateMassLockdown();
	void coordinateBuildingLockdown(int index);

	void coordinateMedicalResponse(int index);

	void resolveIncident(int index);

	void addBuilding(BuildingFacade* building);
};

#endif