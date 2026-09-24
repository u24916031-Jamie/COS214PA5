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
	void coordinateBuildingEvacuation(BuildingFacade* building);	//evacuates specific building

	void coordinateMassLockdown();
	void coordinateBuildingLockdown(BuildingFacade* building);

	void coordinateMedicalResponse(BuildingFacade* building);

	void resolveIncident(BuildingFacade* building);

	void addBuilding(BuildingFacade* building);

	void resolveMassIncident();

};

#endif