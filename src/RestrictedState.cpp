#include "RestrictedState.h"

RestrictedState::RestrictedState()
{
}

RestrictedState::~RestrictedState()
{
}

bool RestrictedState::allowAccess(char d){
    if (d = 'm'){
        return true;
    }
    return false;
}