#ifndef CAMPUSEMERGENCYCOORDINATOR_H
#define CAMPUSEMERGENCYCOORDINATOR_H

#include "StaffMediator.h"
#include <string>

class SecurityService;
class MedicalService;
class FacilityService;
class CommunicationService;

class CampusEmergencyCoordinator : public StaffMediator {

private:
	SecurityService* securityService;
	MedicalService* medicalService;
	FacilityService* facilityService;
	CommunicationService* communicationService;

public:
	CampusEmergencyCoordinator(SecurityService* security,
								MedicalService* medical,
								FacilityService* facility,
								CommunicationService* communication);

	void notify(Staff* sender, const std::string& event) override;
};

#endif
