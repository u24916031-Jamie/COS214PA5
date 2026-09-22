#include "Incident.h"
#include "Reported.h"
#include <iostream>

int Incident::globalIncidentId = 1;

Incident::Incident(std::string description)
{
	this->description = description;
	this->condition = new Reported();
	this->incidentId = globalIncidentId++;

}

void Incident::setCondition(Condition *condition)
{
    this->condition = condition;
}

Condition* Incident::getCondition() {
	return this->condition;
}

void Incident::advance() {
	if (this->condition){
		condition->advance(this);
		std::cout << "Incident " << getDescription() << " with id " << getId() << " has entered the following state: " << condition->printConditionName() << std::endl;
	}
}

int Incident::getId()
{
    return incidentId;
}

std::string Incident::getDescription()
{
    return description;
}



void Incident::notify() {
	for (auto obs : observers){
		obs->update(this);
	}
}
