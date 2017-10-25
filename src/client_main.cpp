/*
 *
 *	Head Template
 *
 */

#include "server/client.hpp"

#include <iostream>
using std::cout;
using std::endl;

int main(int argc, const char *argv[])
{
	// put your code here
	Client *cl = new Client();
	string msg = "Hello echos!";
	cl->send_msg_to_server("localhost", msg);
	delete cl;
	return 0;
}
