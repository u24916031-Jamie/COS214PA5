#ifndef MEDICALSERVICE_H
#define MEDICALSERVICE_H

#include "Staff.h"

#include <string>
#include <iostream>

class MedicalService : public Staff {


public:
	~MedicalService() override = default;

	void sendUpdate(const std::string& event) override;

	void receiveUpdate(const std::string& event) override;
};

#endif
