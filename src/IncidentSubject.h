#ifndef INCIDENTSUBJECT_H
#define INCIDENTSUBJECT_H

#include "Observer.h"
#include <vector>

class IncidentSubject {

private:
	std::vector<Observer*> observers;

public:
	void attach(Observer* observer);

	void detach(Observer* observer);

	void notify();
};

#endif
