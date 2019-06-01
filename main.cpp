#include <QCoreApplication>
#include <calculator.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Calculator calc;
    calc.calculate();
    calc.printResult();

    //return a.exec();
}
