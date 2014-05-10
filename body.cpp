#include "body.h"
#include <iostream>
std::string Body::data()
{
    file.open(fileName,std::ios_base::binary);
    std::string body;
	// 如果打开文件，返回文件内容，打不开，str长度为0 
	// 在 Http::buildHeader(string& body) 中重新构造
    if(file){
// http://en.cppreference.com/w/cpp/io/basic_istream/read
        file.seekg(0, file.end);// get the end of the file
        int length = file.tellg();
        file.seekg(0,file.beg);// get the begin of the file

        body.resize(length, ' ');
        char *beg = &*body.begin(); // * 解引用，& 再取地址
        file.read(beg, length);
        file.close();
    }
        return body;

}
