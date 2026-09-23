#include "BuildingAccessInterface.h"

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
