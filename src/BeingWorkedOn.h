#ifndef BEINGWORKEDON_H
#define BEINGWORKEDON_H

class BeingWorkedOn : Condition {


public:
	void handle(Incident* incident);

	void advance();
};

#endif
