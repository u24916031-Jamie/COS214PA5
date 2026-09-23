#include "CommunicationService.h"
#include "StaffMediator.h"

void CommunicationService::sendUpdate(const std::string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void CommunicationService::receiveUpdate(const std::string&  event) {
	std::cout << "[Communication] " << event << std::endl;
}

bool CommunicationService::restrictedAccessPermission(){
	return false;
}