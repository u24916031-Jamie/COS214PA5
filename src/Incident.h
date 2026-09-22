#ifndef INCIDENT_H
#define INCIDENT_H

#include "IncidentSubject.h"
#include "Condition.h"
#include <string>




class Incident : public IncidentSubject {

private:
	static int globalIncidentId;
	int incidentId;
	std::string description;
	Condition* condition;

public:
	Incident(std::string description);
	void setCondition(Condition* condition);

	Condition* getCondition();

	void advance();
	int getId();
	std::string getDescription();
};

#endif
