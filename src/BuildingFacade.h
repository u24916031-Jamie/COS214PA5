#ifndef BUILDINGFACADE_H
#define BUILDINGFACADE_H

#include "LockBuildingCommand.h"
#include "UnlockBuildingCommand.h"
#include "RestrictBuildingCommand.h"
#include "SecurityService.h"
#include "MedicalService.h"
#include "CommunicationService.h"
#include "BuildingAccessAdapter.h"

class BuildingFacade
{

private:
	std::string name;
	BuildingAccessAdapter *accessSystem;
	LockBuildingCommand *lockCommand;
	UnlockBuildingCommand *unlockCommand;
	RestrictBuildingCommand *restrictCommand;

public:
	BuildingFacade(std::string name, BuildingAccessAdapter *accessSystem, LockBuildingCommand *lockCommand,
				   UnlockBuildingCommand *unlockCommand, RestrictBuildingCommand *restrictCommand);

	void coordinateBuildingEvacuation();

	void coordinateBuildingLockdown();

	void coordinateMedicalResponse();

	void coordinateResolve();

	bool allowStaffAccess(Staff *user);
};

#endif