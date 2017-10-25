

#include "client.hpp"

#include <iostream> // remember to remove


#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>

Client::Client()
{
	
}

Client::~Client()
{

}

void Client::init()
{
	std::cout << "Client::init()" << std::endl;
}


void Client::send_msg_to_server(string host, string msg)
{
	std::cout << "Client::send_msg_to_server()" << std::endl;

	// get addressinfo
	struct addrinfo *res = nullptr;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = PF_INET;
	hints.ai_socktype = SOCK_STREAM;
	if (getaddrinfo(host.c_str(), "tcp", &hints, &res)) {
		throw "Couldn't resolve address";
	}
	// create socket
	int p_sock = -1;
	if ((p_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
		throw "Socket creation failure";
	}

	// connecting
	if (connect(p_sock, res->ai_addr, res->ai_addrlen) < 0) {
		throw "connection failed";
	}

	const char *buffer = msg.c_str();
	write(p_sock, buffer, msg.size());
	std::cout << "Client sent msg: " << msg << std::endl;
	// close socket
	close(p_sock);
}
