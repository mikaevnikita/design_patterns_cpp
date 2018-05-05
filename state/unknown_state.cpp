#include "unknown_state.h"

UnknownState::UnknownState(StateMachine* dfa)
    :State(dfa)
{
    current_state = multiply_four_states::UNKNOWN;
}
void UnknownState::update() override{
    char last_char = *(dfa->getSequance().end() - 1);
    if(last_char == '0')
        dfa->setState(new RestNullState(dfa));
    else if(last_char == '1')
        dfa->setState(new RestOneState(dfa));
}
