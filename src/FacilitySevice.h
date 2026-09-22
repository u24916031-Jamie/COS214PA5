#ifndef FACILITYSEVICE_H
#define FACILITYSEVICE_H

class FacilitySevice : public Staff {


public:
	void sendUpdate(const string& event);

	void receiveUpdate(const string& event);
};

#endif
