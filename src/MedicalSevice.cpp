#include "MedicalSevice.h"
#include "StaffMediator.h"

void MedicalSevice::sendUpdate(const string&  event) {
	if(mediator){
		mediator->notify(this, event);
	}
}

void MedicalSevice::receiveUpdate(const string&  event) {
	std::cout << "[Medical] " << event << std::endl;
}
