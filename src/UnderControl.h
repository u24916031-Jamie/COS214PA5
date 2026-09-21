#ifndef UNDERCONTROL_H
#define UNDERCONTROL_H

#include "Condition.h"
#include "Incident.h"

#include <string>


class UnderControl : public Condition {


public:
	std::string printConditionName();

	void advance(Incident* incident);
};

#endif
