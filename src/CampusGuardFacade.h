#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

#include "CampusEmergencyCoordinator.h"

class CampusGuardFacade {

private:
	CampusEmergencyCoordinator coordinator;

public:
	void coordinateMassEvacuation();

	void resolveIncident();
};

#endif
