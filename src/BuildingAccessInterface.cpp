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

bool BuildingAccessInterface::enter(char userPrefix){
	bool allowed = state->allowAccess(userPrefix);

	// if (allowed){
	// 	cout << "You can enter\n";
	// }
	
	return allowed;
}
