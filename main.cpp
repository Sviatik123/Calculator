#include <QCoreApplication>
#include <calculator.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    while (true)
    {
        Calculator calc;
        calc.calculate();
        calc.printResult();
    }

    //return a.exec();
}
