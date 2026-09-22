#ifndef SECURITYSERVICE_H
#define SECURITYSERVICE_H

#include "Staff.h"

#include <string>
#include <iostream>

class SecurityService : public Staff {


public:
	~SecurityService() override = default;

	void sendUpdate(const std::string& event) override;

	void receiveUpdate(const std::string& event) override;
};

#endif
