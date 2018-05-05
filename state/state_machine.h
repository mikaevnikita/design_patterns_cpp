#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "state.h"
#include "unknown_state.h"
#include <string>

enum multiply_four_states {REST_0, REST_1, REST_2, REST_3, UNKNOWN};

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
#endif // STATE_MACHINE_H
