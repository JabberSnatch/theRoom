#ifndef STEP_H_INCLUDED
#define STEP_H_INCLUDED

#include <string>

class Step {

public:
    virtual Step* runStep() = 0;
    virtual bool hasNext() = 0;

};

class Description
    :public Step {

public:
    std::string text;
    Step* nextStep;


    Description(const std::string& text);

    Step* runStep();
    bool hasNext();
};

class Choice
    :public Step {

public:
    std::string xChoice;
    std::string oChoice;

    Step* xStep;
    Step* oStep;


    Choice(const std::string& xChoice, const std::string& oChoice);

    Step* runStep();
    bool hasNext();
};

#endif // STEP_H_INCLUDED
