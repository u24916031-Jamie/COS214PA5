#ifndef INCIDENT_H
#define INCIDENT_H

#include "Subject.h"
#include "Condition.h"
#include <string>

class BuildingFacade;

class Incident : public Subject
{

private:
	static int globalIncidentId;
	int incidentId;
	std::string description;
	Condition *condition;
	BuildingFacade *buildingFacade;

public:
	Incident(std::string description, BuildingFacade *buildingFacade = nullptr);	//omit if campus-wide (nullptr = campus-wide)
	void setCondition(Condition *condition);

	Condition *getCondition();

	void advance();
	int getId();
	std::string getDescription();
	BuildingFacade *getBuildingFacade();
	bool isCampusWide();
	void notify();
	virtual ~Incident();
};

#endif
