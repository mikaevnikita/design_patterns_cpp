#include "observable.h"

void Observable::addObserver(Observer* observer){
    auto it = std::find(observers.begin(), observers.end(), observer);
    if(it != observers.end())
        return;
    observers.push_back(observer);
}

void Observable::removeObserver(Observer* observer){
    auto it = std::find(observers.begin(), observers.end(), observer);
    observers.erase(it);
}

void Observable::notify(){
    for(Observer*& observer: observers){
        observer->update();
    }
}
