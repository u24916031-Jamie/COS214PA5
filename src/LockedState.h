#ifndef LOCKED_STATE_H
#define LOCKED_STATE_H

#include "BuildingState.h"

class LockedState : public BuildingState
{
private:
    /* data */
public:
    LockedState(/* args */);
    ~LockedState() override;
    virtual bool allowAccess(char d);
};


#endif
