#ifndef INCIDENT_H
#define INCIDENT_H

#include "Subject.h"
#include "Condition.h"
#include <string>




class Incident : public Subject {

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
	void notify();
	~Incident();
};

#endif
