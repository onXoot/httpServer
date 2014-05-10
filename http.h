#ifndef HTTP_H
#define HTTP_H

#include <iostream>
#include <arpa/inet.h>
class Http{

private:
	int port;
	int clientfd,serverfd;
	struct sockaddr_in serverSock,clientSock;
	void error(const char *p){std::cout<<p<<std::endl;}
	std::string buildHeader(std::string&);
	void exeClient(int clifd);
public:
	Http(int p):port(p){}
	~Http(){stop();}
	int 	start();
	void 	stop();
	int 	getPort(){return port;}



};


#endif
