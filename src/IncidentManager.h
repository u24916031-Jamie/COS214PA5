#ifndef INCIDENTMANAGER_H
#define INCIDENTMANAGER_H

class IncidentManager : Observer {

private:
	int activeIncidentsCount;
	Queue<Incident*> incidentQueue;

public:
	void update(Incident* incident);

	void addIncident(Incident* incident);

	void startNextIncident();
};

#endif
