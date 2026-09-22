#include "CommunicationSevice.h"
#include "StaffMediator.h"

void CommunicationSevice::sendUpdate(const string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void CommunicationSevice::receiveUpdate(const string&  event) {
	std::cout << "[Communication] " << event << std::endl;
}
