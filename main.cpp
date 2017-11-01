#include <iostream>
#include <string>
#include "Roman.h"
using namespace std;

int main()
{
    testConstructor();
    testOperatorPlus();
    testOperatorPlusEqual();
    testOperatorIncrement();
    //testOutput();
    Roman r1(85);
    r1.getValue();

    return 0;
}

//testConsoleIO();