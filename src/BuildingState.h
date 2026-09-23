#ifndef BUILDINGSTATE_H
#define BUILDINGSTATE_H

class BuildingState {

public:
    BuildingState();
    virtual ~BuildingState() = default;
    virtual bool allowAccess(char d) = 0;
};

#endif