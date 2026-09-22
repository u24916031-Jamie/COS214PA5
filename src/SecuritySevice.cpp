#include "SecuritySevice.h"
#include "StaffMediator.h"

void SecuritySevice::sendUpdate(const string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void SecuritySevice::receiveUpdate(const string&  event) {
	std::cout << "[Security]" << event << std::endl;
}
