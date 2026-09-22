#ifndef INCIDENT_H
#define INCIDENT_H

#include <string>
#include "IncidentSubject.h"
#include "Condition.h"


class Incident : public IncidentSubject {

private:
	int incidentId;
	std::string description;
	Condition* condition;

public:
	void setCondition(Condition* condition);

	Condition* getCondition();

	void advance();
};

#endif
