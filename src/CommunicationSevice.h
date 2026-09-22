#ifndef COMMUNICATIONSEVICE_H
#define COMMUNICATIONSEVICE_H

class CommunicationSevice : public Staff {


public:
	void sendUpdate(const string& event);

	void receiveUpdate(const string& event);
};

#endif
