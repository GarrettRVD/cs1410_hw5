//
// Created by GRees on 10/26/2017.
//
#include <iostream>
using namespace std;

#include "Roman.h"

/*!
 * Roman: Default Constructor
 */
Roman::Roman() : value(0) {}

/*!
 * Roman: 1 parameter Constructor
 * @param romNum : Initial romNum
 */
Roman::Roman(const string& romNum) : value(0)
{
    convertFromRoman(romNum);
}
/*!
 * Roman: 1 parameter integer Constructor
 * @param x
 */
Roman::Roman(const int& x): value(x)
{
    convertToRoman(value);
}
/*!
 * convertFromRoman : converts Roman Numeral to number
 * @return : the number
 */
void Roman::convertFromRoman(const string& romNum)
{
    int length = romNum.length();

    for (int i = 0; i < length; ++i)
    {
        switch(romNum.at(i))
        {
            case 'I': value = value + 1;
                break;
            case 'X': value = value + 10;
                break;
            case 'L': value = value + 50;
                break;
            case 'V': value = value + 5;
                break;
            case 'M': value = value +1000;
                break;
            case 'D': value = value + 500;
                break;
            case 'C': value = value + 100;
                break;
            default: value += 0;
        }
    }
}

/*!
 * checkTest : tests for pass or fail
 * @param testName : the function it is testing
 * @param whatItShouldBe : the expected result
 * @param obj : a Roman object
 * @return : true or false
 */
bool checkTest(string testName, int whatItShouldBe, const Roman& obj)
{
    if(whatItShouldBe == obj.value)
    {
        cout << "Passed " << testName << endl;
        return true;
    }
    else
    {
        cout << "****** Failed test " << testName << " ****** " << endl
             << "     Object contained: " << obj.value << endl
             << "     Output should have contained: " << whatItShouldBe << endl;
        return false;
    }
}

/*!
 * getValue : gets the value
 * @return : returns the value
 */
unsigned int Roman::getValue() const
{
    return value;
}
string Roman:: getromString(){
    return romString;
}

/*!
 * testOutput : tests the output using convertToRoman
 */

/*void Roman::testOutput()
{
    Roman a("MDCLXVI");
    string b = a.convertToRoman();
    checkTest("testOutput #1", "MDCLXVI", b);

    //This is really the value 7.  Your code should correctly read this in and convert it back to VII.
    Roman c("IIIIIII");
    b = c.convertToRoman();
    checkTest("testOutput #2", "VII", b);
}
*/
/*!
 * testConstructor : tests the constructors
 */
void testConstructor()
{
    //Test to make sure empty objects are set to zero.
    Roman blank;
    checkTest("testConstructor #1", 0, blank);

    //Test reading in a number.
    Roman a("LXVI");
    checkTest("testConstructor #2", 66, a);

    //Test a Bigger Number
    Roman b("MMMDDCCLLXXVVII");
    checkTest("testConstructor #3", 4332, b);
}

/*!
 * testOperatorPlus : testing plus operator with Roman objects
 */
void testOperatorPlus()
{
    //Test adding two roman objects
    Roman a("XVI");
    Roman b("MDCLXVI");
    Roman c = a + b;
    checkTest("testOperatorPlus #1", 1682, c);
    //make sure the left and right operands weren't modified
    checkTest("testOperatorPlus #2", 16, a);
    checkTest("testOperatorPlus #3", 1666, b);

    //Test adding an object with an int
    c = a + 52;
    checkTest("testOperatorPlus #4", 68, c);
    //make sure the left operand wasn't modified
    checkTest("testOperatorPlus #5", 16, a);

    //Test adding an int with an object
    c = 578 + a;
    checkTest("testOperatorPlus #6", 594, c);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlus #7", 16, a);
}

/*!
 * testOperatorPlusEqual : testing plus-equal operator with Roman objects
 */
void testOperatorPlusEqual()
{
    //Test adding two roman objects
    Roman a("MLII");
    Roman b("DDCCI");
    a += b;
    checkTest("testOperatorPlusEqual #1", 2253, a);
    //make sure the right operand wasn't modified
    checkTest("testOperatorPlusEqual #2", 1201, b);

    //Test adding on an integer
    b += 17;
    checkTest("testOperatorPlusEqual #3", 1218, b);
}

/*!
 * testOperatorIncrement : testing increment operator with Roman objects
 */
void testOperatorIncrement()
{
    //Test prefix increment
    Roman a("MLII");
    Roman b("DDCCII");
    b = ++a;
    checkTest("testOperatorIncrement #1", 1053, a);
    checkTest("testOperatorIncrement #2", 1053, b);
}

/*!
 * testConsoleIO : testing console input/output with Roman objects
 */
/*
void testConsoleIO()
{
    //Test reading in the data using the extraction operator >>
    cout << "Enter the text CCLX: ";
    Roman a;
    cin >> a;
    checkTest("testConsoleIO #1", 260, a);

    //Test outputting data using the insertion operator <<
    cout << "testConsoleIO #2" << endl << "If this says 260, this test passed: " << a << endl;
}
*/

/*!
 * operator + overload : <obj> + <obj>
 * @param r1 : a Roman object
 * @return r2 : a Roman object
 */
Roman Roman::operator + (const Roman &r1) const
{
    Roman r2;
    r2.value = value + r1.getValue();
    return r2;
}

/*!
 * operator + overload : <obj> + <const>
 * @param v : a const integer
 * @return r1 : a Roman object
 */
Roman Roman::operator + (const int v) const
{
    Roman r1;
    r1.value = value + v;
    return r1;
}

/*!
 * operator + overload : <const> + <obj>
 * @param v : a const integer
 * @param r1 : a Roman object
 * @return r2 : a Roman object
 */
Roman operator + (const int v, Roman &r1)
{
    Roman r2;
    r2.value = v + r1.getValue();
    return r2;
}

/*!
 * operator += overload : <obj> += <obj>
 * @param r1 : a Roman object
 */
void Roman::operator += (const Roman &r1)
{
    value += r1.getValue();
}

/*!
 * operator += overload : <obj> += <const>
 * @param v : a const integer
 */
void Roman::operator += (const int v)
{
    value += v;
}

/*!
 * operator ++ overload : ++<obj>
 * @return r1 : a Roman object
 */
Roman Roman::operator ++()
{
    Roman r1;
    r1.value = ++value;
    return r1;
}

void Roman::convertToRoman(const int& x)
{
    int totalValue = x;
    string romString = romString;
    do{
        totalValue-=1000;
        romString += "M";
    }while(totalValue>=1000);
    do{
        totalValue-=500;
        romString += "D";
    }while(totalValue>=500);
    do{
        totalValue-=100;
        romString += "C";
    }while(totalValue>=100);
    do{
        totalValue-=50;
        romString += "L";
    }while(totalValue>=50);
    do{
        totalValue-=10;
        romString += "X";
    }while(totalValue>=10);
    do{
        totalValue-=5;
        romString += "V";
    }while(totalValue>=5);
    do{
        totalValue-=1;
        romString += "I";
    }while(totalValue>=1);
}
