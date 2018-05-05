#include <iostream>
#include <string>
using namespace std;

/*
Конечный автомат для чисел кратных четырем на основе паттерна Состояние
+Объектно-ориентированный подход в написании конечных автоматов
+Явно-выраженные переходы между состояниями, нежели при реализации через
switch-case, или матрицу
+Делегирование запроса на состояние
-Разрастается архитектура
*/


enum multiply_four_states {REST_0, REST_1, REST_2, REST_3, UNKNOWN};

class StateMachine;

class State{
protected:
    StateMachine* dfa;
    multiply_four_states current_state;
public:
    State(StateMachine* dfa);
    multiply_four_states state() const;
    virtual void update() = 0;
};


class StateMachine{
private:
    State* state;
    std::string sequance;
public:
    StateMachine();
    void appendZero();
    void appendOne();
    std::string getSequance() const;
    multiply_four_states getCurrentState() const;
    void setState(State* state);
    ~StateMachine();
};

class UnknownState : public State{
public:
    UnknownState(StateMachine* dfa);
    void update() override;
};

class RestNullState : public State{
public:
    RestNullState(StateMachine* dfa);
    void update() override;
};

class RestOneState : public State{
public:
    RestOneState(StateMachine* dfa);
    void update() override;
};

class RestThreeState : public State{
public:
    RestThreeState(StateMachine* dfa);
    void update() override;
};

class RestTwoState : public State{
public:
    RestTwoState(StateMachine* dfa);
    void update() override;
};

State::State(StateMachine* dfa)
:dfa(dfa)
{}

multiply_four_states State::state() const{
    return current_state;
}

StateMachine::StateMachine()
{
    state = new UnknownState(this);
}
void StateMachine::appendZero(){
    sequance.append("0");
    state->update();
}
void StateMachine::appendOne(){
    sequance.append("1");
    state->update();
}
std::string StateMachine::getSequance() const{
    return sequance;
}
multiply_four_states StateMachine::getCurrentState() const{
    return state->state();
}
void StateMachine::setState(State* state){
    delete this->state;
    this->state = state;
}

StateMachine::~StateMachine(){
    delete state;
}

UnknownState::UnknownState(StateMachine* dfa)
:State(dfa)
{
    current_state = multiply_four_states::UNKNOWN;
}
void UnknownState::update(){
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestNullState(dfa));
    else if(last_char == '1')
        dfa->setState(new RestOneState(dfa));
}


RestOneState::RestOneState(StateMachine* dfa)
:State(dfa)
{
    current_state = multiply_four_states::REST_1;
}

void RestOneState::update(){
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestTwoState(dfa));
    else if(last_char == '1')
        dfa->setState(new RestThreeState(dfa));
}

RestTwoState::RestTwoState(StateMachine* dfa)
:State(dfa)
{
    current_state = multiply_four_states::REST_2;
}

void RestTwoState::update(){
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestNullState(dfa));
    else if(last_char == '1')
        dfa->setState(new RestOneState(dfa));
}


RestThreeState::RestThreeState(StateMachine* dfa)
:State(dfa)
{
    current_state = multiply_four_states::REST_3;
}

void RestThreeState::update(){
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestTwoState(dfa));
}
RestNullState::RestNullState(StateMachine* dfa)
:State(dfa)
{
    current_state = multiply_four_states::REST_0;
}

void RestNullState::update(){
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '1')
        dfa->setState(new RestOneState(dfa));
}

int main()
{
    StateMachine sm;
    sm.appendOne();
    sm.appendOne();
    sm.appendZero();
    sm.appendOne();
    cout << sm.getSequance() << " " << (int)sm.getCurrentState() << endl;
    return 0;
}
