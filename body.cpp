#include "body.h"
#include <iostream>
std::string Body::data()
{
    file.open(fileName,std::ios_base::binary);
    std::string body;
	// ������ļ��������ļ����ݣ��򲻿���str����Ϊ0 
	// �� Http::buildHeader(string& body) �����¹���
    if(file){
// http://en.cppreference.com/w/cpp/io/basic_istream/read
        file.seekg(0, file.end);// get the end of the file
        int length = file.tellg();
        file.seekg(0,file.beg);// get the begin of the file

        body.resize(length, ' ');
        char *beg = &*body.begin(); // * �����ã�& ��ȡ��ַ
        file.read(beg, length);
        file.close();
    }
        return body;

}
