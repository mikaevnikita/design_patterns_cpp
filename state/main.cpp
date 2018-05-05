#include <iostream>
#include "state_machine.h"
using namespace std;

int main()
{
    StateMachine sm;
    cout << sm.getSequance() << " " << sm.getCurrentState() << endl;
    return 0;
}
