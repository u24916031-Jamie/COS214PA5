#ifndef FACILITYSERVICE_H
#define FACILITYSERVICE_H

#include "Staff.h"

#include <string>
#include <iostream>

class FacilityService : public Staff {


public:
	~FacilityService() override = default;

	void sendUpdate(const std::string& event) override;

	void receiveUpdate(const std::string& event) override;
};

#endif
