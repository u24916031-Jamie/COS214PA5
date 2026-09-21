#ifndef REPORTED_H
#define REPORTED_H

#include "Condition.h"
#include "Incident.h"

#include <string>

class Reported : public Condition {


public:
	std::string printConditionName();

	void advance(Incident* incident);
};

#endif
