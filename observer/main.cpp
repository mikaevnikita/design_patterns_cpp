#include <iostream>
#include <list>

class Observer;
class Subject;

class Observer
{
private:
    Subject* subject;
public:
    void setSubject(Subject* subject);
    Subject* getSubject();
    virtual void update() = 0;
};


class View1: public Observer{
public:
    void update();
};

class View2: public Observer{
public:
    void update();
};

class State{
private:
    int someData;
public:
    void setData(int newData);
    int getData();
};

class Subject{
private:
    State s;
    std::list<Observer*> observers;
public:
    void addObserver(Observer* observer);
    void removeObserver(Observer* observer);
    void setState(State& newState);
    State getState();
    void notify();
};
void State::setData(int newData){
    someData = newData;
}

int State::getData(){
    return someData;
}

void Subject::addObserver(Observer *observer){
    observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer){
    observers.remove(observer);
}

void Subject::setState(State &newState){
    s = newState;
    notify();
}

State Subject::getState(){
    return s;
}

void Subject::notify(){
    for(Observer* observer : observers){
        observer->update();
    }
}
void Observer::setSubject(Subject *subject){
    this->subject = subject;
    subject->addObserver(this);
}

Subject* Observer::getSubject(){
    return subject;
}

void View1::update(){
    State s = getSubject()->getState();
    std::cout << "View1: " << s.getData() << std::endl;
}

void View2::update(){
    State s = getSubject()->getState();
    std::cout << "View2: " << s.getData() << std::endl;
}


int main()
{
    State current_state;
    current_state.setData(1);

    Subject subject;

    Observer* view1 = new View1;
    Observer* view2 = new View2;

    view1->setSubject(&subject);
    view2->setSubject(&subject);

    subject.setState(current_state);

    std::cout << "---" << std::endl;

    current_state.setData(2);
    subject.setState(current_state);

    return 0;
}
