#ifndef FLYES_H
#define FLYES_H
#include <iostream>

class FlyBehaviour{
public:
    virtual void fly() = 0;
};

class FlyNoWay:public FlyBehaviour{
    //не умеет летать
public:
    void fly();
};


class RocketFly:public FlyBehaviour{
    //Полет на ракетной реактивной тяге
public:
    void fly();
};


#endif // FLYES_H
