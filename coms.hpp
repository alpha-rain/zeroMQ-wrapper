#ifndef COMS
#define COMS

#include <iostream>
#include <ratio>
#include <chrono>
#include <ctime>
#include <time.h>
#include <unistd.h> //usleep
#include <memory>   //shared_ptr


#include "cppzmq/zmq.hpp"

using namespace std;
using namespace zmq;
class Coms
{
	private:
	shared_ptr<context_t> Context;
    shared_ptr<socket_t>  Socket;
	
	int Type_;
	string Bind;
	public:
	Coms(){}
	Coms(int type_, string bind, string servCli){init(type_,bind,servCli);}
	bool init(int type_, string bind, string servCli);
	void send(string msg);
	string get();
	
	
};

#endif