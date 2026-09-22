#ifndef SECURITYSEVICE_H
#define SECURITYSEVICE_H

#include "Staff.h"

class SecuritySevice : public Staff {


public:
	void sendUpdate(const string& event) override;

	void receiveUpdate(const string& event) override;
};

#endif
