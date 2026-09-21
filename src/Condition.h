#ifndef CONDITION_H
#define CONDITION_H

class Condition {


public:
	virtual void handle(Incident* incident) = 0;

	virtual void advance() = 0;
};

#endif
