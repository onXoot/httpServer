#include "http.h"
#include "header.h"
#include "body.h"
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <thread>
using namespace std;
int Http::start()
{
	serverfd = socket(AF_INET, SOCK_STREAM, 0);
	if(-1 == serverfd){
		error("socket error!");
		return -1;
	}
	memset(&serverSock, 0, sizeof(serverSock));
    serverSock.sin_family = AF_INET;
	serverSock.sin_port  = htons(port);
	serverSock.sin_addr.s_addr = htonl(INADDR_ANY); // ���� IP  0.0.0.0
    int stat = ::bind(serverfd, (struct sockaddr*)&serverSock, sizeof(serverSock));
    // ��ֹ�� algorithm ��� bind ײ��
	if(-1 == stat ){
		error("bind error!");
		return -2;
	}
	if(-1 == listen(serverfd, 10)){
		error("listen error");
		return -3;
	}
	cout<<"now listen on port:"<<port<<endl;
	while(1){
        socklen_t len = sizeof(clientSock);
        clientfd = accept(serverfd, (struct sockaddr*)&clientSock, &len);
        if(clientfd == -1){
            error("accept error!");
            return -4;
        }
        std::thread(&Http::exeClient, this, clientfd).detach();
	}
	return 0;
}

void Http::exeClient(int clifd)
{
        char buf[1024];
        while(1){
            recv(clifd, buf, 1024, 0);
            //cout<<buf<<endl;
            //cout<<"clifd:"<<clifd<<" port:"<<clientSock.sin_port<<endl;
            if(strlen(buf)==0) {
            	cout<<"bad request"<<endl;
            	continue;
            }
            Header h(buf); 
            h.readHeader(); // ����httpͷ
            Body b(h.getTarget()); // Ҫ��ȡ���ļ���
            string body(b.data()); // ��ȡ�ļ�
            string head(buildHeader(body)); // ���췵��������� http ͷ
            string content = head + body;
            send(clifd, content.c_str(), content.size(), 0);
        }
}

void Http::stop(){
	close(serverfd);
}

string Http::buildHeader(string& body)
{
    size_t length = body.size();

    stringstream ss;
    // ���body�ĳ���Ϊ�㣬 ���ж�Ϊ404�� Ȼ�����¹��� body, ���Բ���û����const����
    if(0 == length) {
        ss<<"HTTP/1.1 404 Not Found\r\n";
        string b("<html><head><title>404 Not Found</title></head>"
                 "<body><h1>Not Found</h1></body></html>");
        length = b.size();
        body = b;
    }
    else{
        ss<<"HTTP/1.1 200 OK\r\n";
    }
    ss<<"Cache-Control: private\r\n";
    ss<<"Server: linux-miniWeb\r\n";
    ss<<"Content-Type: text/html; charset=UTF-8\r\n";
    ss<<"Content-Length: ";
    ss<<length;
    ss<<"\r\n\r\n";


    string head(ss.str());
    return head;
}
