#include "BuildingAccessInterface.h"

BuildingAccessInterface::BuildingAccessInterface(){
	state = new UnlockedState();
}

void BuildingAccessInterface::setState(BuildingState* x){
	delete state;
	state = x;
}
