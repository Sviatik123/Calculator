#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include"parser.h"
#include"converter.h"
#include"validator.h"
#include<cmath>

class Calculator
{
public:
    Calculator();
    void calculate();
    void printResult();
    bool getIsValid();
private:
    std::string exp;
    std::string polExp;
    double result;
    bool isValid;
};

#endif // CALCULATOR_H
