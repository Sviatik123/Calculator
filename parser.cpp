#include "parser.h"

Parser::Parser() {}

std::string Parser::parse(int size, char* arr[])
{
   std::string a = "";
   return std::accumulate(arr + 1, arr + size, a);
}

std::string Parser::parse()
{
    std::string exp;
    std::cout<<"Enter expression: ";
    getline(std::cin,exp);
    return exp;
}

