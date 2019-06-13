#include <QCoreApplication>
#include <calculator.h>
#include<cctype>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    while (true)
    {
        Calculator calc;
        if(calc.getIsValid())
        {
            calc.calculate();
            calc.printResult();
        }
        else
        {
            std::cout<<"Invalid expression\n";
        }
    }


    //return a.exec();
}
