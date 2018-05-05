#include "rest_one_state.h"

RestOneState::RestOneState(StateMachine* dfa)
    :State(dfa)
{
    current_state = multiply_four_states::REST_1;
}

void RestOneState::update() override{
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestTwoState(dfa));
    else if(last_char == '1')
        dfa->setState(new RestThreeState(dfa));
}
