#include "state.h"

State(StateMachine* dfa)
    :dfa(dfa)
{}

multiply_four_states State::state() const{
    return current_state;
}
