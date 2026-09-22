#ifndef MEDICALSEVICE_H
#define MEDICALSEVICE_H

class MedicalSevice : public Staff {


public:
	void sendUpdate(const string& event);

	void receiveUpdate(const string& event);
};

#endif
