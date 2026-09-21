#ifndef MEDICALSEVICE_H
#define MEDICALSEVICE_H

class MedicalSevice : Staff {


public:
	void sendUpdate(string event);

	void receiveUpdate(string event);
};

#endif
