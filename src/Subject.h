#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>
class Observer;

class Subject {

protected:
	std::vector<Observer*> observers;

public:
	void attach(Observer* observer);

	void detach(Observer* observer);

	virtual void notify() = 0;
};

#endif
