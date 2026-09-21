#ifndef INCIDENTSUBJECT_H
#define INCIDENTSUBJECT_H

class IncidentSubject {

private:
	vector<Observer*> observers;

public:
	void attach(Observer* observer);

	void detach(Observer* observer);

	void notify();
};

#endif
