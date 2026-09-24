#include "IncidentManager.h"
#include "Incident.h"

#include "SecurityService.h"
#include "MedicalService.h"
#include "FacilityService.h"
#include "CommunicationService.h"

#include "CampusEmergencyCoordinator.h"

#include "BuildingAccessAdapter.h"

#include "LockBuildingCommand.h"
#include "UnlockBuildingCommand.h"
#include "RestrictBuildingCommand.h"

#include "CampusGuardFacade.h"

#include "BuildingFacade.h"

#include <iostream>

int main()
{
    std::cout << "=================================" << " CAMPUSGUARD " << "=================================\n"
              << std::endl;

    // Mediator Setup
    SecurityService security;
    MedicalService medical;
    FacilityService facility;
    CommunicationService communication;

    CampusEmergencyCoordinator coordinator(&security, &medical, &facility, &communication);

    security.setMediator(&coordinator);
    medical.setMediator(&coordinator);
    facility.setMediator(&coordinator);
    communication.setMediator(&coordinator);

    // Adapter Setup
    BuildingAccessAdapter ITaccessSystem;
    BuildingAccessAdapter DHaccessSystem;
    BuildingAccessAdapter LIBaccessSystem;

    // Command Setup
    // IT BUILDING
    LockBuildingCommand ITlockCommand(&ITaccessSystem);
    UnlockBuildingCommand ITunlockCommand(&ITaccessSystem);
    RestrictBuildingCommand ITrestrictCommand(&ITaccessSystem);

    // DINING HALL
    LockBuildingCommand DHlockCommand(&DHaccessSystem);
    UnlockBuildingCommand DHunlockCommand(&DHaccessSystem);
    RestrictBuildingCommand DHrestrictCommand(&DHaccessSystem);

    // LIBRARY
    LockBuildingCommand LIBlockCommand(&LIBaccessSystem);
    UnlockBuildingCommand LIBunlockCommand(&LIBaccessSystem);
    RestrictBuildingCommand LIBrestrictCommand(&LIBaccessSystem);

    BuildingFacade *IT = new BuildingFacade("IT", &ITaccessSystem, &ITlockCommand, &ITunlockCommand, &ITrestrictCommand);
    BuildingFacade *DiningHall = new BuildingFacade("DINING HALL", &DHaccessSystem, &DHlockCommand, &DHunlockCommand, &DHrestrictCommand);
    BuildingFacade *library = new BuildingFacade("LIBRARY", &LIBaccessSystem, &LIBlockCommand, &LIBunlockCommand, &LIBrestrictCommand);

    // Facade Setup
    CampusGuardFacade facade(&security, &medical, &communication);

    facade.addBuilding(IT);
    facade.addBuilding(DiningHall);

    // Observer + State Setup
    IncidentManager incidentManager(3);

    Incident *fire = new Incident("Fire detected in the IT Building.", IT);

    Incident *zombie = new Incident("Unauthorized access detected in Residence Hall.", DiningHall);

    Incident *medicalEmergency = new Incident("Student collapsed outside the library.", library);

    incidentManager.addIncident(fire);
    incidentManager.addIncident(zombie);
    incidentManager.addIncident(medicalEmergency);

    std::cout << "\nA staff member reports smoke " << "coming from the IT Building.\n"
              << std::endl;

    Incident *active = incidentManager.startNextIncident();

    if (active)
    {
        std::cout << "\nActive Incident:\n"
                  << active->getDescription() << std::endl;

        std::cout << "\nThe incident is now being worked on." << std::endl;

        BuildingFacade *building = active->getBuildingFacade();

        // BeingWorkedOn -> UnderControl
        active->advance();

        if (building == nullptr)
        {
            std::cout << "\nCampusGuard initiates a mass evacuation." << std::endl;
            facade.coordinateMassEvacuation();
        }
        else
        {
            std::cout << "\nCampusGuard initiates an evacuation." << std::endl;
            facade.coordinateBuildingEvacuation(building);
        }

        std::cout << "\nResponders are coordinating..." << std::endl;

        // UnderControl -> Resolved
        active->advance();

        std::cout << "\nThe fire has been contained." << std::endl;

        if (building != nullptr)
        {
            facade.resolveIncident(building);
        }
        else
        {
            facade.resolveMassIncident();
        }
    }

    std::cout << "\n======================================================\n"
              << "First incident resolved. Dispatching next incident." << "\n======================================================\n"
              << std::endl;

    active = incidentManager.startNextIncident();

    if (active)
    {
        std::cout << "\nActive Incident:\n"
                  << active->getDescription() << std::endl;

        BuildingFacade *building = active->getBuildingFacade();

        active->advance();

        if (building == nullptr)
        {
            std::cout << "\nCampusGuard initiates a mass lockdown." << std::endl;
            facade.coordinateMassLockdown();
        }
        else
        {
            std::cout << "\nCampusGuard initiates a building lockdown." << std::endl;
            facade.coordinateBuildingLockdown(building);
        }

        CommunicationService *person = new CommunicationService();
        std::cout << "\nCommunication Service Guy tries to enter." << std::endl;

        if (building->allowStaffAccess(person))
        {
            std::cout << "Communication Service Guy allowed to enter." << std::endl;
        }
        else
        {
            std::cout << "Communication Service Guy not allowed to enter." << std::endl;
        }

        active->advance();

        std::cout << "\nThreat neutralized." << std::endl;

        if (building != nullptr)
        {
            facade.resolveIncident(building);
        }
        else
        {
            facade.resolveMassIncident();
        }
    }

    std::cout << "\n======================================================\n"
              << "Second incident resolved. Dispatching next incident." << "\n======================================================\n"
              << std::endl;

    active = incidentManager.startNextIncident();

    if (active)
    {
        std::cout << "\nActive Incident:\n"
                  << active->getDescription() << std::endl;

        BuildingFacade *building = active->getBuildingFacade();

        active->advance();

        std::cout << "\nCampusGuard initiates medical response." << std::endl;

        facade.coordinateMedicalResponse(building);

        std::cout << "\nPatient stabilized." << std::endl;

        if (building != nullptr)
        {
            facade.resolveIncident(building);
        }
        else
        {
            facade.resolveMassIncident();
        }
    }

    delete fire;
    delete zombie;
    delete medicalEmergency;

    delete library;
    delete IT;
    delete DiningHall;

    std::cout << "\n========" << " INCIDENTS SUCCESSFULLY RESOLVED " << "========" << std::endl;

    return 0;
}