#ifndef QUACKS_H
#define QUACKS_H
#include <iostream>

class QuackBehaviour{
public:
    virtual void quack() = 0;
};

class Quack: public QuackBehaviour{
public:
    void quack();
};


class MuteQuack: public QuackBehaviour{
    //Молчит
public:
    void quack();
};

#endif // QUACKS_H
