#include "Incident.h"
#include "Reported.h"
#include "Observer.h"
#include "IncidentManager.h"
#include <iostream>

int Incident::globalIncidentId = 1;

Incident::Incident(std::string description, BuildingFacade* buildingFacade)
{
	this->description = description;
	this->condition = new Reported();
	this->buildingFacade = buildingFacade;
	this->incidentId = globalIncidentId++;
	std::cout << description << std::endl;

}

void Incident::setCondition(Condition *condition)
{
	delete this->condition;
    this->condition = condition;
}

Condition* Incident::getCondition() {
	return this->condition;
}

void Incident::advance() {
	if (this->condition){
		condition->advance(this);
		std::cout << "Incident with id " << getId() << " has entered the following state: " << condition->printConditionName() << std::endl;
		if (condition->printConditionName() == "Resolved."){
			notify();
		}
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

BuildingFacade* Incident::getBuildingFacade()
{
	return buildingFacade;
}

bool Incident::isCampusWide()
{
	return buildingFacade == nullptr;
}



void Incident::notify() {
	for (auto obs : observers){
		obs->update(this);
	}
}

Incident::~Incident()
{
	for (auto obs : observers){
		delete condition;
		if (IncidentManager* im = dynamic_cast<IncidentManager*>(obs)){
			im->removeIncident(this);
		}
	}
}
