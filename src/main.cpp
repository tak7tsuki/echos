/*
 *
 *	Head Template
 *
 */

#include "server/server.hpp"

#include <iostream>
using std::cout;
using std::endl;

class Test {
public:
	static void foo(int n) {
		cout << n << endl;
	}
};

int main(int argc, const char *argv[])
{
	// put your code here
	Server *se = new Server();
	se->run();
	delete se;
	return 0;
}
