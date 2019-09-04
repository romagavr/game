#ifndef FACTORY_H
#define FACTORY_H

#include "block2.h"

class Factory {
public:
    virtual Block2* create()=0;
    virtual ~Factory(){}
};

class FloorFactory: public Factory {
public:
    Block2* create(){
        return new Floor;
    }
};

#endif // FACTORY_H
