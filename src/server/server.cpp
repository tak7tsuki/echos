

#include "server.hpp"

#include <iostream> // remember to remove

// #include <string.h>
#include <err.h>
#include <netdb.h>
#include <unistd.h>
#include <thread>

Server::Server()
{
	
}

Server::~Server()
{

}

void Server::init()
{
	std::cout << "Server::init()" << std::endl;
}

void Server::handle_request(int socket, struct sockaddr addr, socklen_t len)
{
	// socket handling code

	// get the information from the socket
	char *buffer = new char[10];
	while (true) {
		int nob = -1;
		if ((nob = read(socket, buffer, 10)) < 1) {
			break;
		}
		for (int f = 0; f < nob; f++) {
			std::cout << buffer;
		}
	}
	std::cout << std::endl;
	delete[] buffer;
	close(socket);
	// process the information
}

void Server::run()
{
	std::cout << "Server::run()" << std::endl;

	// get addressinfo
	struct addrinfo *res = nullptr;
	struct addrinfo hints;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = PF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;
	int err = getaddrinfo(nullptr, "tcp", &hints, &res);
	if (err) {
		errx(1, "%s", gai_strerror(err));
		std::cout << "getaddrinfo() returned an error: " << gai_strerror(err) << std::endl;
		throw "Couldn't resolve address";
	}
	// create socket
	int p_sock = -1;
	if ((p_sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
		std::cout << "socket() returned an error" << std::endl;
		throw "Socket creation failure";
	}
	// bind socket
	if (bind(p_sock, res->ai_addr, res->ai_addrlen) < 0) {
		std::cout << "bind() returned an error" << std::endl;
		throw "Socket bind failure";
	}

	// listen to a port
	if (listen(p_sock, 20) < 0) {
		std::cout << "listen() returned an error" << std::endl;
		throw "Socket listen failed";
	}

	// accepting requests
	while (true) {
		int i_sock = -1;
		struct sockaddr n_addr;
		socklen_t n_len;
		i_sock = accept(p_sock, &n_addr, &n_len);
		if (i_sock < 0) {
			std::cout << "accept() returned an error" << std::endl;
			throw "Socket accept failure";
		}
		std::thread *nt = new std::thread(handle_request, i_sock, n_addr, n_len);
	}
	// close socket
	close(p_sock);
}
