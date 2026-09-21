#ifndef RESOLVED_H
#define RESOLVED_H


#include "Condition.h"
#include "Incident.h"
#include <string>

class Resolved : public Condition {


public:
	std::string printConditionName();

	void advance(Incident* incident);
};

#endif
