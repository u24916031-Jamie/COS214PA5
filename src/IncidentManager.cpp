#include "IncidentManager.h"
#include <iostream>

IncidentManager::IncidentManager()
{
	activeIncidentsCount = 3;
}

IncidentManager::IncidentManager(int incidentCount)
{
	activeIncidentsCount = incidentCount;
	if (incidentCount < 1){
		activeIncidentsCount = 3;
	}
	std::cout << "There are " << activeIncidentsCount << " available teams ready to deal with incidents." << std::endl;
}

void IncidentManager::update(Subject *subject)
{
	if (auto* incident = dynamic_cast<Incident*>(subject)){

		if (incident->getCondition()->printConditionName() == "Resolved."){
			activeIncidentsCount++;
		}
		std::cout << "There are now: " << activeIncidentsCount << " teams on standby."<< std::endl;
	}
}

void IncidentManager::addIncident(Incident* incident) {
	if (incident == nullptr){
		return;
	}
	for (auto inci : incidentQueue){
		if (inci == incident){
			return;
		}
	}
	incidentQueue.push_back(incident);
	incident->attach(this);
	std::cout << "Incident with id "<< incident->getId() << " has been added to the queue."<< std::endl;
	

}

void IncidentManager::removeIncident(Incident* incident) {
	if (incident == nullptr){
		return;
	}
	for (auto it = incidentQueue.begin();it!= incidentQueue.end();it++){
		if (*it == incident){
			incidentQueue.erase(it);
			return;
		}
	}

}

Incident* IncidentManager::startNextIncident() {
	if (incidentQueue.empty()){
		std::cout << "There are no incidents in queue." << std::endl;
		return nullptr;
	}
	if (activeIncidentsCount == 0){
		std::cout << "There are not enough teams on standby." << std::endl;
		return nullptr;
	}

	if (activeIncidentsCount > 0){

		std::cout << "Dispatching team to handle incident with ID: " << incidentQueue.front()->getId() << std::endl;
		incidentQueue.front()->advance();
		auto* incident = incidentQueue.front();
		incidentQueue.erase(incidentQueue.begin());
		activeIncidentsCount--;
		std::cout << "There are " << activeIncidentsCount << " teams remaining on standby." << std::endl;
		return incident;
	}

	return nullptr;
}

IncidentManager::~IncidentManager()
{
	for (auto* inci: incidentQueue){
		inci->detach(this);

	}
}
