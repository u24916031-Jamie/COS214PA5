#ifndef INCIDENTMANAGER_H
#define INCIDENTMANAGER_H

#include "Incident.h"
#include "Observer.h"
#include <queue>

class IncidentManager : public Observer {

private:
	int activeIncidentsCount;
	std::queue<Incident*> incidentQueue;

public:
	IncidentManager(int incidentCount);
	void update(Incident* incident);

	void addIncident(Incident* incident);

	void startNextIncident();
};

#endif
