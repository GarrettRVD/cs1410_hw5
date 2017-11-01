#include <iostream>
#include <string>
#include "Roman.h"
using namespace std;

int main()
{
    //testConstructor();
    //testOperatorPlus();
    //testOperatorPlusEqual();
    //testOperatorIncrement();
    //testOutput();
    Roman test(1666);
    cout<<test.convertToRoman();
    return 0;
}

//testConsoleIO();