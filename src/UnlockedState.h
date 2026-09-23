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
    bool UnlockedState::allowAccess(Staff* x) override;
};

#endif
