#ifndef HEADER_H
#define HEADER_H

#include <string>
#include <map>
using namespace std;
class Header{
private:
// 写的太多了， 暂时用不上 看着RFC2616 乱写的
	string Accept;
	string Accept_Charset;
	string Accept_Encoding;
	string Accept_Language;
	string Accept_Range;
	string Age;
	string Allow;
	string Authorization;
	string Cache_Control;
	string Connection;
	string Content_Encoding;
	string Content_Language;
	string Content_Length;
	string Content_Location;
	string Content_MD5;
	string Content_Range;
	string Content_Type;
	string Date;
	string ETag;
	string Expect;
	string Expires;
	string From;
	string Host;
	string If_Match;
	string If_Modifed_Since;
	string If_None_Match;
	string If_Range;
	string If_Unmodified_Since;
	string Last_Modified;
	string Location;
	string Max_Forwards;
	string Pragma;
	string Proxy_Authenticate;
	string Proxy_Authorization;
	string Range;
	string Referer;
	string Retry_After;
	string Server;
	string TE;
	string Trailer;
	string Transfer_Encoding;
	string Upgrade;
	string User_Agent;
	string Vary;
	string Via;
	string Warning;
	string WWW_Authenticate;

	string DNT; // do not track
	string method;
	string httpVersion;
	string request;
	string target;

    void readHeaderField(const string &headerField);
	std::map<string, int> headMap;
	void buildMap();


public:
    Header(const char *httpRequest):request(httpRequest)
    { 
            //buildMap();
    }
    void readHeader();


    string getAccept(){return Accept;}
    string getAcceptCharset(){return Accept_Charset;}
    string getAcceptEncoding(){return Accept_Encoding;}
    string getAcceptLanguage(){return Accept_Language;}
    string getContentEncoding(){return Content_Encoding;}
    string getContentLength(){return Content_Length;}
    string getConnection(){return Connection;}
    string getHost(){return Host;}
    string getPragma(){return Pragma;}
    string getTarget(){return target;}
    string getUserAgent(){return User_Agent;}


};


#endif
