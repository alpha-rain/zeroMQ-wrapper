#include "coms.hpp"

bool Coms::init(int type_, string bind, string servCli)
{
	Type_ = type_;
	Bind  = bind;
	Context.reset(new context_t(1));
	Socket.reset(new socket_t(*Context, type_));
	if(servCli[0] == 's')
	{
		Socket->bind(bind);
	}
	else if(servCli[0] == 'c')
	{
		Socket->connect(bind);
	}
}

void Coms::send(string msg)
{
	zmq::message_t reply(msg.length());
	memcpy((void *) reply.data (), msg.c_str(), msg.length());
	Socket->send(reply);
}
string Coms::get()
{
	message_t reply;
	Socket->recv(&reply);
	
	string rpl = std::string(static_cast<char*>(reply.data()), reply.size());
	return rpl;
}
