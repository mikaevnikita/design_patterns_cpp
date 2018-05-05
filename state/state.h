#ifndef STATE_H
#define STATE_H

#include "state_machine.h"

class State{
protected:
    StateMachine* dfa;
    multiply_four_states current_state;
public:
    State(StateMachine* dfa);
    multiply_four_states state() const;
    virtual void update() = 0;
};

#endif // STATE_H
