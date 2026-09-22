#ifndef OBSERVER_H
#define OBSERVER_H

#include "Subject.h"

class Observer {


public:
	virtual void update(Subject* incident) = 0;
};

#endif
