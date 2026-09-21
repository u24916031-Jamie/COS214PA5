#ifndef BEINGWORKEDON_H
#define BEINGWORKEDON_H

#include "Incident.h"
#include <string>

class BeingWorkedOn : public Condition {


public:
	std::string printConditionName();

	void advance(Incident* incident);
};

#endif
