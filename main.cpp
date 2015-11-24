//clang++ -Wall -Wc++11-extensions -o main main.cpp -lwiringPi
//g++ -Wall -o main main.cpp -lwiringPi

#include <iostream>
#include "coms.hpp"
using namespace std;
int main (void)
{
	Coms coms(ZMQ_PUSH,"tcp://127.0.0.1:420", "c");
	for(int i = 0;i < 10;i++)
	{
		coms.send("Hi dude");
		//cout<<coms.get()<<endl;
	}
	return 0 ;
}