#ifndef COMMUNICATIONSERVICE_H
#define COMMUNICATIONSERVICE_H

#include "Staff.h"

#include <string>
#include <iostream>

class CommunicationService : public Staff {


public:
	~CommunicationService() override = default;

	void sendUpdate(const std::string& event) override;

	void receiveUpdate(const std::string& event) override;

	bool restrictedAccessPermission() override;
};

#endif
