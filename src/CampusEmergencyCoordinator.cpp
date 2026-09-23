#include "CampusEmergencyCoordinator.h"
#include "MedicalService.h"
#include "FacilityService.h"
#include "CommunicationService.h"
#include "SecurityService.h"

CampusEmergencyCoordinator::CampusEmergencyCoordinator(SecurityService* security,
							MedicalService* medical,
							FacilityService* facility,
							CommunicationService* communication)
							{
								securityService = security;
								medicalService = medical;
								facilityService = facility;
								communicationService = communication;

							}

void CampusEmergencyCoordinator::notify(Staff* sender, const std::string& event){
    (void)sender;
    if(event == "FireDetected")
    {
        medicalService->receiveUpdate(
            "Prepare emergency response");

        facilityService->receiveUpdate(
            "Prepare evacuation");

        communicationService->receiveUpdate(
            "Issue fire alert");
    }
    else if(event == "MedicalEmergency")
    {
        facilityService->receiveUpdate(
            "Clear emergency routes");

        communicationService->receiveUpdate(
            "Notify nearby responders");
    }
    else if(event == "IntruderDetected")
    {
        securityService->receiveUpdate(
            "Dispatch additional guards");

        communicationService->receiveUpdate(
            "Issue security warning");
    }
    else if(event == "GasLeakDetected")
    {
        facilityService->receiveUpdate(
            "Shut down affected systems");

        securityService->receiveUpdate(
            "Secure danger zone");

        communicationService->receiveUpdate(
            "Issue gas leak warning");
    }
    else if(event == "PowerFailure")
    {
        facilityService->receiveUpdate(
            "Investigate outage");

        communicationService->receiveUpdate(
            "Notify affected buildings");
    }
    else if(event == "AllClear")
    {
        communicationService->receiveUpdate(
            "Send all-clear notice");

        facilityService->receiveUpdate(
            "Resume normal operations");
    }
}