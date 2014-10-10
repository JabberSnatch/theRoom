#include <iostream>

#include "Step.h"

using namespace std;

#TODO (Samu#1#): Add some modularity to the script (i.e. [key|password])

int main () {

    Description start = Description("You are standing in a room. On the wall facing you are two doors. One is labeled \"good\" door, and the other one is labeled \"bad\" door. Next to the good door stands a guard. ");
    Choice door = Choice("Open the good door", "Open the bad door");

    Description goodDoor = Description("Before your hand can reach the doorknob, the guard stops you. He explains that in order to through the good door you first have to search the room for a password and say it to him.");
    Description badDoor = Description("As you try to open the bad door, you notice that it is locked. The guard sees you struggling with the door and tells you that he lost the key to the bad door somewhere in the room, and that if you want it, you will have to look for it.");
    Description firstLook = Description("You look around and discover that the room is filled with furniture and useless items.");
    Choice bookshelf_desk = Choice("Search the bookshelf", "Search the desk");

    Description bookshelfDesc = Description("You start browsing through the books. You notice that one of them looks a bit odd, and might be the trigger for some hidden mechanism.");
    Choice bookshelfChoi = Choice("Pull the book", "Not pull the book");
    Description pullTheBook = Description("You pull the book out of the bookshelf and wait... But nothing happens. Well, at least you've tried.");
    Description nPullTheBook = Description("You leave the book where it is and go back to your quest for the [key|password].");

    Description deskDesc = Description("The desk is covered in dust. You don't find anything useful on top of it. However, on the top drawer are written the following word : \"There is nothing interesting in there.\"");
    Choice deskChoi = Choice("Open the drawer", "Not open the drawer");
    Description openTheDrawer = Description("As you open the drawer, you find out that it is filled with wood shavings. You take a few seconds to embrace your own disappointment, and close the drawer back.");
    Description nOpenTheDrawer = Description("You leave the drawer as it is, thinking that if it says it is not interesting, then it probably isn't.");

    Description secndLook = Description("You are now looking around you, hoping to find other places to search.");
    Choice closet_table = Choice("Search the closet", "Search the table");

    start.nextStep = &door;
    door.xStep = &goodDoor;
    door.oStep = &badDoor;
    goodDoor.nextStep = &firstLook;
    badDoor.nextStep = &firstLook;

    firstLook.nextStep = &bookshelf_desk;
    bookshelf_desk.xStep = &bookshelfDesc;
    bookshelf_desk.oStep = &deskDesc;

    bookshelfDesc.nextStep = &bookshelfChoi;
    bookshelfChoi.xStep = &pullTheBook;
    bookshelfChoi.oStep = &nPullTheBook;
    pullTheBook.nextStep = &secndLook;
    nPullTheBook.nextStep = &secndLook;

    deskDesc.nextStep = &deskChoi;
    deskChoi.xStep = &openTheDrawer;
    deskChoi.oStep = &nOpenTheDrawer;
    openTheDrawer.nextStep = &secndLook;
    nOpenTheDrawer.nextStep = &secndLook;

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
