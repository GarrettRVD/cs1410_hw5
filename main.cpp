#include <iostream>
#include <string>
#include "Roman.h"
using namespace std;

void testConstructor();
//void testOperatorPlus();
//void testOperatorPlusEqual();
//void testOperatorIncrement();
//void testConsoleIO();
int main() {

    //testConstructor();
    //testOperatorPlus();
    //testOperatorPlusEqual();
    //testOperatorIncrement();
    //testOutput();
    Roman r1("LXVI");
    r1.convertFromRoman();
    r1.printRoman();
    return 0;
}