#ifndef INCIDENTMANAGER_H
#define INCIDENTMANAGER_H

#include "Observer.h"
#include <vector>
#include "Incident.h"


class IncidentManager : public Observer {

private:
	int activeIncidentsCount;
	std::vector<Incident*> incidentQueue;

public:
IncidentManager();
	IncidentManager(int incidentCount);	
	void update(Subject* subject);

	void addIncident(Incident* incident);
	void removeIncident(Incident* incident);

	Incident* startNextIncident();

	~IncidentManager();
};

#endif
