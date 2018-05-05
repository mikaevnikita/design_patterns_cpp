#ifndef REST_TWO_STATE_H
#define REST_TWO_STATE_H

#include "state.h"
#include "rest_null_state.h"
#include "rest_one_state.h"

class RestTwoState : public State{
public:
    RestTwoState(StateMachine* dfa);
    void update() override;
};

#endif // REST_TWO_STATE_H
