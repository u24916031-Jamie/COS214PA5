#ifndef CAMPUSGUARDFACADE_H
#define CAMPUSGUARDFACADE_H

class CampusGuardFacade {

private:
	CampusEmergencyCoordinator coordinator;

public:
	void coordinateMassEvacuation();

	void resolveIncident();
};

#endif
