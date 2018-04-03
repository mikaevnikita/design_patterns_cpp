#ifndef DUCKS_H
#define DUCKS_H

#include "flyes.h"
#include "quacks.h"
#include <iostream>

class Duck{
private:
    FlyBehaviour* flyBehaviour;
    QuackBehaviour* quackBehaviour;
public:
    Duck();
    void setFlyBehaviour(FlyBehaviour* newFlyBehaviour);
    void setQuackBehaviour(QuackBehaviour* newQuackBehaviour);
    void performQuack();
    void performFly();
    virtual void display() = 0;
    ~Duck();
};


class RedheadDuck: public Duck{
    void display() override;
};



#endif // DUCKS_H
