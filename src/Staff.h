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

	virtual void setMediator(StaffMediator* m);

	virtual void sendUpdate(const std::string& event) = 0;

	virtual void receiveUpdate(const std::string& event) = 0;

	virtual bool restrictedAccessPermission() = 0;
};

#endif
