#ifndef Restricted_State
#define Restricted_State

#include "BuildingState.h"

class RestrictedState : public BuildingState
{
private:
    /* data */
public:
    RestrictedState(/* args */);
    ~RestrictedState() override;
    virtual bool RestrictedState::allowAccess(char d);
};


#endif
