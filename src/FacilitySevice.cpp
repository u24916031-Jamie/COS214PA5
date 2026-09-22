#include "FacilitySevice.h"
#include "StaffMediator.h"

void FacilitySevice::sendUpdate(const string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void FacilitySevice::receiveUpdate(const string&  event) {
	std::cout << "[Facility] " << event << std::endl;
}
