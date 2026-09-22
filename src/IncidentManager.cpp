#include "IncidentManager.h"
#include <iostream>


IncidentManager::IncidentManager(int incidentCount)
{
	activeIncidentsCount = incidentCount;
	if (incidentCount < 1){
		activeIncidentsCount = 3;
	}
}

void IncidentManager::update(Incident *incident)
{
	if (incident->getCondition()->printConditionName() == "Resolved."){
		activeIncidentsCount++;
	}
	std::cout << "There are now: " << activeIncidentsCount << " teams on standby."<< std::endl;
}

void IncidentManager::addIncident(Incident* incident) {
	incidentQueue.push(incident);

}

void IncidentManager::startNextIncident() {
	if (incidentQueue.empty()){
		std::cout << "There are no incidents in queue." << std::endl;
		return;
	}
	if (activeIncidentsCount == 0){
		std::cout << "There are not enough teams on standby." << std::endl;
		return;
	}

	if (activeIncidentsCount > 0){
		std::cout << "Dispatching team to handle incident with ID: " << incidentQueue.front()->getId() << std::endl;
		incidentQueue.front()->advance();
		incidentQueue.pop();
		activeIncidentsCount--;
	}

}
