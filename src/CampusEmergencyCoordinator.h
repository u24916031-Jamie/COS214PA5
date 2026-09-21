#ifndef CAMPUSEMERGENCYCOORDINATOR_H
#define CAMPUSEMERGENCYCOORDINATOR_H

class CampusEmergencyCoordinator : StaffMediator {

private:
	SecurityService* securityService;
	MedicalService* medicalService;
	FacilityService* facilityService;
	CommunicationService* communicationService;

public:
	void notify(Staff* sender, string event);
};

#endif
