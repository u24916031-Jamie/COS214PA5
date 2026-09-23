#include "SecurityService.h"
#include "StaffMediator.h"

void SecurityService::sendUpdate(const std::string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void SecurityService::receiveUpdate(const std::string&  event) {
	std::cout << "[Security] " << event << std::endl;
}

bool SecurityService::restrictedAccessPermission(){
	return true;
}