#include "converter.h"

Converter::Converter()
{

}

std::string Converter::convert(std::string exp)
{
    std::string polExp;
    polExp = "";
    exp += " ";
    std::stack<std::string> expression;
    size_t length = exp.length();
    for (size_t i = 0; i < length - 1; i++)
    {
        if (exp[i] >= 48 && exp[i] <= 57)
        {
            polExp += exp[i];
            while (exp[i + 1] != '+'&& exp[i + 1] != '-'&& exp[i + 1] != '*'&& exp[i + 1] != '/'&& exp[i + 1] != '^'&& exp[i + 1] != ' '&& exp[i + 1] != '('&& exp[i + 1] != ')')
            {
                polExp += exp[i + 1];
                i++;
            }
            polExp += " ";
        }
        else if (exp[i] == ' ')
        {
            continue;
        }
        else if (exp[i] == '(')
        {
            expression.push("(");
        }
        else if (exp[i] == ')')
        {
            while (expression.top() != "(")
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.pop();
        }
        else if (exp[i] == '+')
        {
            while (!expression.empty() && (expression.top() == "+" || expression.top() == "-" || expression.top() == "*" || expression.top() == "/" || expression.top() == "^"))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("+");
        }
        else if (exp[i] == '-')
        {
            if (i == 0 || exp[i - 1] == '(')
            {
                polExp += exp[i];
                while (exp[i + 1] != '+'&& exp[i + 1] != '-'&& exp[i + 1] != '*'&& exp[i + 1] != '/'&& exp[i + 1] != '^'&& exp[i + 1] != ' '&& exp[i + 1] != '('&& exp[i + 1] != ')')
                {
                    polExp += exp[i + 1];
                    i++;
                }
                polExp += " ";
            }
            else
            {
                while (!expression.empty() && (expression.top() == "+" || expression.top() == "-" || expression.top() == "*" || expression.top() == "/" || expression.top() == "^"))
                {
                    polExp += expression.top();
                    expression.pop();
                    polExp += ' ';
                }
                expression.push("-");
            }
        }
        else if (exp[i] == '*')
        {
            while (!expression.empty() && (expression.top() == "*" || expression.top() == "/" || expression.top() == "^"))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("*");
        }
        else if (exp[i] == '/')
        {
            while (!expression.empty() && (expression.top() == "*" || expression.top() == "/" || expression.top() == "^"))
            {
                polExp += expression.top();
                expression.pop();
                polExp += ' ';
            }
            expression.push("/");
        }
        else if (exp[i] == '^')
        {
            expression.push("^");
        }
    }
    while (!expression.empty())
    {
        polExp += expression.top();
        expression.pop();
        polExp += " ";
    }
    return polExp;
}

