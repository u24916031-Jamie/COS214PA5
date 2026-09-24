#include "LockedState.h"

LockedState::LockedState()
{
}

LockedState::~LockedState()
{
}

bool LockedState::allowAccess(Staff* x){
    return false;
}