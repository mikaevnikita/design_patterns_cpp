#ifndef UNKNOWN_STATE_H
#define UNKNOWN_STATE_H

#include "state.h"
#include "rest_null_state.h"
#include "rest_one_state.h"

class UnknownState : public State{
public:
    UnknownState(StateMachine* dfa);
    void update() override;
};
#endif // UNKNOWN_STATE_H
