#include "rest_three_state.h"

RestThreeState::RestThreeState(StateMachine* dfa)
    :State(dfa)
{
    current_state = multiply_four_states::REST_3;
}

void RestThreeState::update() override{
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestTwoState(dfa));
}
