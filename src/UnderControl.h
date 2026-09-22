#ifndef UNDERCONTROL_H
#define UNDERCONTROL_H

#include "Condition.h"
#include "Incident.h"

#include <string>


class UnderControl : public Condition {


public:
	std::string printConditionName() override;

	void advance(Incident* incident) override;
};

#endif
