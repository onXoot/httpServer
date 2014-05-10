#ifndef BODY_H
#define BODY_H

#include <fstream>
#include <string>
class Body{
private:
    std::ifstream file;
    std::string fileName;


public:
    Body(const std::string &name):fileName(name){}
    std::string data();



};
#endif
