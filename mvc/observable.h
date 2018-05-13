#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"
#include <vector>
using namespace std;

class Observable{
private:
    vector<Observer*> observers;
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void notify();
};

#endif // OBSERVABLE_H
