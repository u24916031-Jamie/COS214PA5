#ifndef FACILITYSEVICE_H
#define FACILITYSEVICE_H

class FacilitySevice : Staff {


public:
	void sendUpdate(string event);

	void receiveUpdate(string event);
};

#endif
