#ifndef STAFFMEDIATOR_H
#define STAFFMEDIATOR_H

#include <string>

class Staff;

class StaffMediator {


public:
	virtual ~StaffMediator();
	virtual void notify(Staff* sender, const std::string& event) = 0;
};

#endif
