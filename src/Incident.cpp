#include "Incident.h"

void Incident::setCondition(Condition* condition) {
	this->condition = condition;
}

Condition* Incident::getCondition() {
	return this->condition;
}

void Incident::advance() {
	// TODO - implement Incident::advance
	throw "Not yet implemented";
}
