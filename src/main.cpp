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

#include <iostream>

int main()
{
    std::cout << "=================================" << " CAMPUSGUARD "  << "=================================\n" << std::endl;

    // Mediator Setup
    SecurityService security;
    MedicalService medical;
    FacilityService facility;
    CommunicationService communication;

    CampusEmergencyCoordinator coordinator( &security, &medical, &facility, &communication);

    security.setMediator(&coordinator);
    medical.setMediator(&coordinator);
    facility.setMediator(&coordinator);
    communication.setMediator(&coordinator);

    // Adapter Setup
    BuildingAccessAdapter accessSystem;

    // Command Setup
    LockBuildingCommand lockCommand(&accessSystem);
    UnlockBuildingCommand unlockCommand(&accessSystem);
    RestrictBuildingCommand restrictCommand(&accessSystem);

    // Facade Setup
    CampusGuardFacade facade(&coordinator, &lockCommand, &unlockCommand, &restrictCommand);

    // Observer + State Setup
    IncidentManager incidentManager(3);

    Incident* fire = new Incident("Fire detected in the IT Building.");

    Incident* zombie = new Incident("Unauthorized access detected in Residence Hall.");

    Incident* medicalEmergency = new Incident("Student collapsed outside the library.");


    incidentManager.addIncident(fire);
    incidentManager.addIncident(zombie);
    incidentManager.addIncident(medicalEmergency);

    std::cout << "\nA staff member reports smoke "<< "coming from the IT Building.\n" << std::endl;

    Incident* active = incidentManager.startNextIncident();

    if(active)
    {
        std::cout << "\nActive Incident:\n" << active->getDescription() << std::endl;

        std::cout << "\nThe incident is now being worked on." << std::endl;

        // BeingWorkedOn -> UnderControl
        active->advance();

        std::cout << "\nCampusGuard initiates a mass evacuation." << std::endl;

        facade.coordinateMassEvacuation();

        std::cout<< "\nResponders are coordinating..."<< std::endl;

        // UnderControl -> Resolved
        active->advance();

        std::cout << "\nThe fire has been contained." << std::endl;

        facade.resolveIncident();
    }

    std::cout << "\n======================================================\n"<< 
        "First incident resolved. Dispatching next incident." << 
        "\n======================================================\n" << std::endl;

    active = incidentManager.startNextIncident();

    if(active)
    {
        std::cout << "\nActive Incident:\n" << active->getDescription() << std::endl;

        active->advance();

        std::cout << "\nCampusGuard initiates a building lockdown." << std::endl;

        facade.coordinateBuildingLockdown();

        active->advance();

        std::cout << "\nThreat neutralized." << std::endl;

        facade.resolveIncident();
    }

    std::cout << "\n======================================================\n"<< 
    "Second incident resolved. Dispatching next incident."<< 
    "\n======================================================\n" << std::endl;

    active = incidentManager.startNextIncident();

    if(active)
    {
        std::cout << "\nActive Incident:\n" << active->getDescription() << std::endl;

        active->advance();

        std::cout << "\nCampusGuard initiates medical response." << std::endl;

        facade.coordinateMedicalResponse();

        active->advance();

        std::cout << "\nPatient stabilized." << std::endl;

        facade.resolveIncident();
    }

    delete fire;
    delete zombie;
    delete medicalEmergency;

    std::cout << "\n========" << " INCIDENTS SUCCESSFULLY RESOLVED " << "========" << std::endl;

    return 0;
}