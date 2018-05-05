#ifndef REST_THREE_STATE_H
#define REST_THREE_STATE_H

#include "state.h"
#include "rest_two_state.h"

class RestThreeState : public State{
public:
    RestThreeState(StateMachine* dfa);
    void update() override;
};
#endif // REST_THREE_STATE_H
