#include "Staff.h"
#include "StaffMediator.h"

Staff::Staff(){
	mediator = nullptr;
}

~Staff::Staff(){
}

void Staff::setMediator(StaffMediatorr* m) {
	mediator = m;
	
}
