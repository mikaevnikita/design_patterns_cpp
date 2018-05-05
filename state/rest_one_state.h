#ifndef REST_ONE_STATE_H
#define REST_ONE_STATE_H

#include "state.h"
#include "rest_two_state.h"
#include "rest_three_state.h"

class RestOneState : public State{
public:
    RestOneState(StateMachine* dfa);
    void update() override;
};
#endif // REST_ONE_STATE_H
