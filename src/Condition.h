#ifndef CONDITION_H
#define CONDITION_H

#include <string>

class Condition {


public:
	virtual std::string printConditionName() = 0;

	virtual void advance(Incident* incident) = 0;
};

#endif
