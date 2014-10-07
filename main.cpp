#include <iostream>

#include "Step.h"

using namespace std;

int main () {

    Step test = Step(
        "You are standing in a room. On the wall facing you are two doors. One is labeled \"good\" door, and the other one is labeled \"bad\" door. Next to the good door stands a guard. ",
        "Open the good door",
        "Open the bad door");

    test.runStep();



    return 0;
}
