#include "UnderControl.h"
#include "Resolved.h"
std::string UnderControl::printConditionName() {
	return "Under control.";

}
void UnderControl::advance(Incident* incident) {
incident->setCondition(new Resolved());
}
