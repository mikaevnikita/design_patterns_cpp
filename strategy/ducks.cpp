#include "ducks.h"

Duck::Duck(){
    flyBehaviour = nullptr;
    quackBehaviour = nullptr;
}

void Duck::setFlyBehaviour(FlyBehaviour* newFlyBehaviour){
    delete flyBehaviour;
    flyBehaviour = newFlyBehaviour;
}

void Duck::setQuackBehaviour(QuackBehaviour* newQuackBehaviour){
    delete quackBehaviour;
    quackBehaviour = newQuackBehaviour;
}

void Duck::performFly(){
    flyBehaviour->fly();
}

void Duck::performQuack(){
    quackBehaviour->quack();
}

Duck::~Duck(){
    delete flyBehaviour;
    delete quackBehaviour;
}

void RedheadDuck::display(){
    std::cout << "Im redhead duck" << std::endl;
}
