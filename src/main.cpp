
#include "IncidentManager.h"
#include "Incident.h"
#include <iostream>

void TestIncidentManagerSystem(IncidentManager* IM){
    
    Incident* fire = new Incident("IT building has caught fire.");
    Incident* fight = new Incident("Two students have gotten into a fight.");
    Incident* injury = new Incident("A student fell down some stairs and broke their arm.");
    Incident* shooting = new Incident("A firefight has broken out in the library.");
    Incident* zombie = new Incident("Zombies have taken control of the engineering building.");
    
    
    IM->addIncident(fire);
    IM->addIncident(fight);
    IM->addIncident(injury);
    IM->addIncident(shooting);
    IM->addIncident(zombie);


    Incident* active = IM->startNextIncident();

    std::cout << active->getDescription() << std::endl;
    active->advance();
    active->advance();

    delete fire;
    delete fight;
    delete injury;
    delete shooting;
    delete zombie;

}

int main(){

    IncidentManager* incidentManager = new IncidentManager(3);
    TestIncidentManagerSystem(incidentManager);





    delete incidentManager;

}