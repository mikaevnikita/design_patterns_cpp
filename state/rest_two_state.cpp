#include "rest_two_state.h"

RestTwoState::RestTwoState(StateMachine* dfa)
    :State(dfa)
{
    current_state = multiply_four_states::REST_2;
}

void RestTwoState::update() override{
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestNullState(dfa));
    else if(last_char == '1')
        dfa->setState(new RestOneState(dfa));
}
