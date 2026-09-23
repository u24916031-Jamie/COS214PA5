#include "BuildingAccessInterface.h"
// #include iostream

BuildingAccessInterface::BuildingAccessInterface(){
	state = new UnlockedState();
}

BuildingAccessInterface::~BuildingAccessInterface(){
	delete state;
}

void BuildingAccessInterface::setState(BuildingState* x){
	delete state;
	state = x;
}

bool BuildingAccessInterface::enter(Staff* x){
	state->allowAccess(x);
}
