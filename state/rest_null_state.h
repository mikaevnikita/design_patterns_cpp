#ifndef REST_NULL_STATE_H
#define REST_NULL_STATE_H

#include "state.h"
#include "rest_one_state.h"

class RestNullState : public State{
public:
    RestNullState(StateMachine* dfa);
    void update() override;
};
#endif // REST_NULL_STATE_H
