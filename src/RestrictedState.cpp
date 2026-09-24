#include "RestrictedState.h"

RestrictedState::RestrictedState()
{
}

RestrictedState::~RestrictedState()
{
}

bool RestrictedState::allowAccess(Staff* x){
    return x->restrictedAccessPermission();
}