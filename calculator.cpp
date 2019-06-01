#include "calculator.h"

Calculator::Calculator()
{
    Parser pars;
    exp = pars.parse();
    Converter conv;
    polExp = conv.convert(exp);
    result = 0;
}

void Calculator::calculate()
{
    std::string inp = "";
    std::stack<double> expression;
    for (size_t i = 0; i < polExp.length(); i++)
    {
        if (polExp[i] != '+'&&polExp[i] != '-'&&polExp[i] != '*'&&polExp[i] != '/'&&polExp[i] != '^'&&polExp[i] != ' ')
        {
            while (polExp[i] != ' ')
            {
                inp += polExp[i];
                i++;
            }
            double operand = stod(inp);
            expression.push(operand);
            inp = "";
            i--;
        }
        else if (polExp[i] == ' ')
        {
            continue;
        }
        else if (polExp[i] == '+')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(firstOper + secondOper);
        }
        else if (polExp[i] == '-')
        {
            if (polExp[i + 1] == ' ')
            {
                double firstOper, secondOper;
                secondOper = expression.top();
                expression.pop();
                firstOper = expression.top();
                expression.pop();
                expression.push(firstOper - secondOper);
            }
            else
            {
                while (polExp[i] != ' ')
                {
                    inp += polExp[i];
                    i++;
                }
                double operand = stod(inp);
                expression.push(operand);
                inp = "";
                i--;
            }
        }
        else if (polExp[i] == '*')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(firstOper * secondOper);
        }
        else if (polExp[i] == '/')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(firstOper / secondOper);
        }
        else if (polExp[i] == '^')
        {
            double firstOper, secondOper;
            secondOper = expression.top();
            expression.pop();
            firstOper = expression.top();
            expression.pop();
            expression.push(pow(firstOper, secondOper));
        }
    }
    result = expression.top();
}

void Calculator::printResult()
{
    std::cout<<result<<std::endl;
}
