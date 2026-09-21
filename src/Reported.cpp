#include "Reported.h"
#include "BeingWorkedOn.h"

std::string Reported::printConditionName() {
	return "Reported.";

}
void Reported::advance(Incident* incident) {
	incident->setCondition(new BeingWorkedOn());
}
