#include "Subject.h"

void Subject::attach(Observer* observer) {
	if (observer == nullptr){
		return;
	}
	for (auto obs : observers){
		if (obs == observer){
			return;
		}
	}
	this->observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
	if (observer == nullptr){
		return;
	}
	for (auto it = observers.begin();it != observers.end();it++){
		if (*it == observer){
			observers.erase(it);
			return;
		}
	}
}
