#ifndef RESOLVED_H
#define RESOLVED_H

class Resolved : Condition {


public:
	void handle(Incident* incident);

	void advance();
};

#endif
