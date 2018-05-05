#include "rest_null_state.h"

RestNullState::RestNullState(StateMachine* dfa)
    :State(dfa)
{
    current_state = multiply_four_states::REST_0;
}

void RestNullState::update() override{
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '1')
        dfa->setState(new RestOneState(dfa));
}
