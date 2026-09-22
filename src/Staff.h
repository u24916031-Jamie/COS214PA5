#ifndef STAFF_H
#define STAFF_H

#include <string>

class StaffMediator;

class Staff {

protected:
	StaffMediator* mediator;

public:
	Staff();

	virtual ~Staff();

	virtual void setMediator(StaffMediatorr* m);

	virtual vvoid sendUpdate(string event) = 0;

	virtual vvoid receiveUpdate(string event) = 0;
};

#endif
