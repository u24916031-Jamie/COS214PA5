#ifndef REPORTED_H
#define REPORTED_H

class Reported : Condition {


public:
	void handle(Incident* incident);

	void advance();
};

#endif
