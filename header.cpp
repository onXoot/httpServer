#include "header.h"
#include <utility>
#include <iostream>
#include <sstream>
using namespace std;

void Header::readHeader()
{
// 火狐的请求

//	GET / HTTP/1.1
//	Host: localhost:8080
//	User-Agent: Mozilla/5.0 (X11; Ubuntu; Linux i686; rv:26.0) Gecko/20100101 Firefox/26.0
//	Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
//	Accept-Language: en-US,en;q=0.5
//	Accept-Encoding: gzip, deflate
//	Connection: keep-alive
//	Cache-Control: max-age=0

    string methodLine("GET / HTTP/1.1");
    if(request.find('\n') != string::npos)
    	methodLine = request.substr(0, request.find('\n'));
    else {
    	cout<<"error in header.cpp line 20"<<endl;
        cout<<"request:"<<endl;
        cout<<request<<endl;
    }
    istringstream stream(methodLine);
    string headerFieldLine;
    stream>>method; //  GET
    stream>>target; //  /index.html
    
    // target.size()==1 即 target 为 /
    if(target.size() == 1) target = "index.html";
    else if(target.size()>1)   target = target.substr(1); // 去掉 /index.html 的 /
    else cout<<"error in header.cpp line 34"<<endl;
    cout<<"target:\t"<<target<<endl;


    /*
    stream>>httpVersion;
    httpVersion = httpVersion.substr(httpVersion.find('/')+1);
    request = request.substr(request.find('\n')+1);
    int pos = request.find('\n');
    while((pos != -1)&&(request.size()>2)){
        headerFieldLine = request.substr(0, pos);
        request = request.substr(pos+1);
        readHeaderField(headerFieldLine);
        pos = request.find('\n');
    }
    */
}

// 暂时用不上
void Header::readHeaderField(const string& field)
{

    string name = field.substr(0, field.find(':'));
    string value = field.substr(field.find(':')+2);

    switch(headMap[name]){
        case 1:  Accept              = value; break;
        case 2:  Accept_Charset      = value; break;
        case 3:  Accept_Encoding     = value; break;
        case 4:  Accept_Language     = value; break;
        case 5:  Accept_Range        = value; break;
        case 6:  Age                 = value; break;
        case 7:  Allow               = value; break;
        case 8:  Authorization       = value; break;
        case 9:  Cache_Control       = value; break;
        case 10: Connection          = value; break;
        case 11: Content_Encoding    = value; break;
        case 12: Content_Language    = value; break;
        case 13: Content_Length      = value; break;
        case 14: Content_Location    = value; break;
        case 15: Content_MD5         = value; break;
        case 16: Content_Range       = value; break;
        case 17: Content_Type        = value; break;
        case 18: Date                = value; break;
        case 19: ETag                = value; break;
        case 20: Expect              = value; break;
        case 21: Expires             = value; break;
        case 22: From                = value; break;
        case 23: Host                = value; break;
        case 24: If_Match            = value; break;
        case 25: If_Modifed_Since    = value; break;
        case 26: If_None_Match       = value; break;
        case 27: If_Range            = value; break;
        case 28: If_Unmodified_Since = value; break;
        case 29: Last_Modified       = value; break;
        case 30: Location            = value; break;
        case 31: Max_Forwards        = value; break;
        case 32: Pragma              = value; break;
        case 33: Proxy_Authenticate  = value; break;
        case 34: Proxy_Authorization = value; break;
        case 35: Range               = value; break;
        case 36: Referer             = value; break;
        case 37: Retry_After         = value; break;
        case 38: Server              = value; break;
        case 39: TE                  = value; break;
        case 40: Trailer             = value; break;
        case 41: Transfer_Encoding   = value; break;
        case 42: Upgrade             = value; break;
        case 43: User_Agent          = value; break;
        case 44: Vary                = value; break;
        case 45: Via                 = value; break;
        case 46: Warning             = value; break;
        case 47: WWW_Authenticate    = value; break;
        case 48: DNT                 = value; break;
        default : break;

    }

}

void Header::buildMap()
{
   headMap.insert(make_pair("Accept",           1));
   headMap.insert(make_pair("Accept-Charset",   2));
   headMap.insert(make_pair("Accept-Encoding",  3));
   headMap.insert(make_pair("Accept-Language",  4));
   headMap.insert(make_pair("Accept-Range",     5));
   headMap.insert(make_pair("Age",              6));
   headMap.insert(make_pair("Allow",            7));
   headMap.insert(make_pair("Authorization",    8));
   headMap.insert(make_pair("Cache-Control",    9));
   headMap.insert(make_pair("Connection",       10));
   headMap.insert(make_pair("Content-Encoding", 11));
   headMap.insert(make_pair("Content-Language", 12));
   headMap.insert(make_pair("Content-Length",   13));
   headMap.insert(make_pair("Content-Location", 14));
   headMap.insert(make_pair("Content-MD5",      15));
   headMap.insert(make_pair("Content-Range",    16));
   headMap.insert(make_pair("Content-Type",     17));
   headMap.insert(make_pair("Date",             18));
   headMap.insert(make_pair("ETag",             19));
   headMap.insert(make_pair("Expect",           20));
   headMap.insert(make_pair("Expires",          21));
   headMap.insert(make_pair("From",             22));
   headMap.insert(make_pair("Host",             23));
   headMap.insert(make_pair("If-Match",         24));
   headMap.insert(make_pair("If-Modifed-Since", 25));
   headMap.insert(make_pair("If-None-Match",    26));
   headMap.insert(make_pair("If-Range",         27));
   headMap.insert(make_pair("If-Unmodified-Since", 28));
   headMap.insert(make_pair("Last-Modified",    29));
   headMap.insert(make_pair("Location",         30));
   headMap.insert(make_pair("Max-Forwards",     31));
   headMap.insert(make_pair("Pragma",           32));
   headMap.insert(make_pair("Proxy-Authenticate", 33));
   headMap.insert(make_pair("Proxy-Authorization", 34));
   headMap.insert(make_pair("Range",            35));
   headMap.insert(make_pair("Referer",          36));
   headMap.insert(make_pair("Retry-After",      37));
   headMap.insert(make_pair("Server",           38));
   headMap.insert(make_pair("TE",               39));
   headMap.insert(make_pair("Trailer",          40));
   headMap.insert(make_pair("Transfer-Encoding",41));
   headMap.insert(make_pair("Upgrade",          42));
   headMap.insert(make_pair("User-Agent",       43));
   headMap.insert(make_pair("Vary",             44));
   headMap.insert(make_pair("Via",              45));
   headMap.insert(make_pair("Warning",          46));
   headMap.insert(make_pair("WWW-Authenticate", 47));
   headMap.insert(make_pair("DNT",              48));
}


