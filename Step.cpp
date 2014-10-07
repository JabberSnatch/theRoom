#include "Step.h"

#include <iostream>

Step::Step(std::string desc, std::string x, std::string o)
    :description(desc), xChoice(x), oChoice(o), choice(0)
{}

void Step::runStep() {
    std::cout << description << std::endl;
    std::cout << "X - " << xChoice << std::endl;
    std::cout << "O - " << oChoice << std::endl << std::endl;

    std::string input = "";
    bool askInput = true;
    while (askInput) {
        std::cin >> input;
        if (input == "X" || input == "x") {
            choice = 1;
            askInput = false;
        }
        else if (input == "O" || input == "o") {
            choice = 2;
            askInput = false;
        }
        else {
            std::cout << "Either X or O, no other alternative" << std::endl << std::endl;
        }
    }
}
