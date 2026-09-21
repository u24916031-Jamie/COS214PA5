#ifndef STAFF_H
#define STAFF_H

class Staff {

private:
	StaffMediator* mediator;

public:
	void setMediator(StaffMediatorr* m);

	void sendUpdate(string event);

	void receiveUpdate(string event);
};

#endif
