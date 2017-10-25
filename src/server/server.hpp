
#ifndef __SERVER_CPP__
#define __SERVER_CPP__

/*
 * Server class
 * Base server for accepting requests and delegating the to corresponding handlers.
 * 
 */

#include <sys/socket.h>
#include <sys/types.h>

class Server {
private:
public:
	Server();
	~Server();

	void init();
	void run();

	static void handle_request(int socket, struct sockaddr addr, socklen_t len);
};

#endif
