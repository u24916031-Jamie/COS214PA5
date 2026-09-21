#ifndef SECURITYSEVICE_H
#define SECURITYSEVICE_H

class SecuritySevice : Staff {


public:
	void sendUpdate(string event);

	void receiveUpdate(string event);
};

#endif
