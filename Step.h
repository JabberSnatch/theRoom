#ifndef STEP_H_INCLUDED
#define STEP_H_INCLUDED

#include <string>

class Step {

public:
    std::string description;
    std::string xChoice;
    std::string oChoice;

    Step* xStep;
    Step* oStep;

    int choice;

    Step(std::string desc, std::string x, std::string o);

    void runStep();
    //TODO (Samu#1#): Maybe add stuff in here?

};

#endif // STEP_H_INCLUDED
