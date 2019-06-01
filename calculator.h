#ifndef CALCULATOR_H
#define CALCULATOR_H
#include<string>
#include"parser.h"
#include"converter.h"
#include<cmath>

class Calculator
{
public:
    Calculator();
    void calculate();
    void printResult();
private:
    std::string exp;
    std::string polExp;
    double result;
};

#endif // CALCULATOR_H
