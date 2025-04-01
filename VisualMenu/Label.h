#ifndef LABEL
#define LABEL
#include "Object.h"

#include <iostream>

class Label :
    protected Object
{
public:
    Label();
    Label(short _x, short _y, std::string _name);
    ~Label();

    int print();

private:
    std::string name;
};

#endif