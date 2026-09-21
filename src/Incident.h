#ifndef INCIDENT_H
#define INCIDENT_H

class Incident : IncidentSubject {

private:
	int incidentId;
	string description;
	Condition* condition;

public:
	void setCondition(Condition* condition);

	Condition* getCondition();

	void advance();
};

#endif
