#include "MedicalService.h"
#include "StaffMediator.h"

void MedicalService::sendUpdate(const std::string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void MedicalService::receiveUpdate(const std::string&  event) {
	std::cout << "[Medical] " << event << std::endl;
}

bool MedicalService::restrictedAccessPermission(){
	return true;
}
