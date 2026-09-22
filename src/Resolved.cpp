#include "Resolved.h"
#include <iostream>
std::string Resolved::printConditionName() {
	return "Resolved.";

}
void Resolved::advance(Incident* incident) {
	std::cout << "Condition (" << incident->getDescription() << ") with id " << incident->getId() << " has already been resolved." << std::endl;
	return;
}
