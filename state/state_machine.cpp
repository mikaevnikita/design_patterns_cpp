#include "state_machine.h"

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
    delete state;
    this->state = state;
}

StateMachine::~StateMachine(){
    delete state;
}
