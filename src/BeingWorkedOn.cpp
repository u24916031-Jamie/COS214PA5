#include "BeingWorkedOn.h"
#include "UnderControl.h"

std::string BeingWorkedOn::printConditionName() {
	return "Being worked on.";

}

void BeingWorkedOn::advance(Incident* incident) {
	incident->setCondition(new UnderControl());

}
