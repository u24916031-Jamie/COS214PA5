#ifndef UNDERCONTROL_H
#define UNDERCONTROL_H

class UnderControl : Condition {


public:
	void handle(Incident* incident);

	void advance();
};

#endif
