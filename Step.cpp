#include "Step.h"

#include <iostream>

Description::Description(const std::string& text)
    :text(text), nextStep(NULL)
{}

Step* Description::runStep() {
    std::cout << std::endl << text << std::endl;

    return nextStep;
}

bool Description::hasNext() {
    return (nextStep != NULL);
}


Choice::Choice(const std::string& xChoice, const std::string& oChoice)
    :xChoice(xChoice), oChoice(oChoice), xStep(NULL), oStep(NULL)
{}

Step* Choice::runStep() {
    std::cout << "X - " << xChoice << std::endl;
    std::cout << "O - " << oChoice << std::endl;

    Step* ret = NULL;
    std::string input = "";
    bool askInput = true;
    while (askInput) {
        std::cin >> input;
        if (input == "X" || input == "x") {
            ret = xStep;
            askInput = false;
        }
        else if (input == "O" || input == "o") {
            ret = oStep;
            askInput = false;
        }
        else {
            std::cout << "Either X or O, no other alternative" << std::endl << std::endl;
        }
    }

    return ret;
}

bool Choice::hasNext() {
    return (xStep != NULL && oStep != NULL);
}
