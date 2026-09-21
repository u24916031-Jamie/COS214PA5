#ifndef COMMUNICATIONSEVICE_H
#define COMMUNICATIONSEVICE_H

class CommunicationSevice : Staff {


public:
	void sendUpdate(string event);

	void receiveUpdate(string event);
};

#endif
