
#ifndef __CLIENT_CPP__
#define __CLIENT_CPP__

/*
 * Server class
 * Base server for accepting requests and delegating the to corresponding handlers.
 * 
 */

#include <string>
using std::string;

class Client {
private:
public:
	Client();
	~Client();

	void init();
	void send_msg_to_server(string address, string msg);

};

#endif
