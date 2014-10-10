#include <iostream>

#include "Step.h"

using namespace std;

int main () {

    Description start = Description("You are standing in a room. On the wall facing you are two doors. One is labeled \"good\" door, and the other one is labeled \"bad\" door. Next to the good door stands a guard. ");
    Choice door = Choice("Open the good door", "Open the bad door");
    Description goodDoor = Description("Before your hand can reach the doorknob, the guard stops you. He explains that in order to through the good door you first have to search the room for a password and say it to him.");
    Description badDoor = Description("As you try to open the bad door, you notice that it is locked. The guard sees you struggling with the door and tells you that he lost the key to the bad door somewhere in the room, and that if you want it, you will have to look for it.");

    start.nextStep = &door;
    door.xStep = &goodDoor;
    door.oStep = &badDoor;

    Step* currentStep = &start;
    bool running = true;
    while (running) {
        if (currentStep->hasNext()) {
            currentStep = currentStep->runStep();
        }
        else {
            running = false;
            currentStep->runStep();
        }
    }

    return 0;
}
