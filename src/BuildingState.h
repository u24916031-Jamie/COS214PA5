#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

#include "Staff.h"

class BuildingState {

public:
    BuildingState();
    virtual ~BuildingState() = default;
    virtual bool allowAccess(Staff* x) = 0;
};

#endif