#include "FacilityService.h"
#include "StaffMediator.h"

void FacilityService::sendUpdate(const std::string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void FacilityService::receiveUpdate(const std::string&  event) {
	std::cout << "[Facility] " << event << std::endl;
}

bool FacilityService::restrictedAccessPermission(){
	return true;
}
