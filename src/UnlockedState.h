#ifndef UNLOCKED_STATE_H
#define UNLOCKED_STATE_H

#include "BuildingState.h"

class UnlockedState : public BuildingState
{
private:
    /* data */
public:
    UnlockedState(/* args */);
    ~UnlockedState() override;
    virtual bool UnlockedState::allowAccess(char d);
};

#endif
