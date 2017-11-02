//
// Created by Garrett Van Dyke on 10/26/2017.
//

#ifndef HOUSE_GRAYJOY_HW5_TASK1_ROMAN_H
#define HOUSE_GRAYJOY_HW5_TASK1_ROMAN_H
#include <iostream>
#include <string>
using namespace std;

class Roman
{
    private:
        unsigned int value;
        string romString;
    public:
        Roman();                                // This allows us to make empty objects. (Default Constructor)
        Roman(const string&);                   // This takes a Roman numeral as a string.

        void convertFromRoman(const string&);   // Converts Roman numeral to a decimal number
        string convertToRoman();                // The method that helps us take an integer and turn it into a roman numeral

        unsigned int getValue() const;          // Gets the value of a Roman object

        // Testing
        friend bool checkTest(string testName, int whatItShouldBe, const Roman& obj);
        friend bool checkTest(string testName, string whatItShouldBe, string whatItIs);
        friend void testOutput();

        // Plus Operator Overloads
        Roman operator + (const Roman &r1) const;           // <obj> + <obj>
        Roman operator + (int v) const;                     // <obj> + <const>
        friend Roman operator + (const int v, Roman &r1);   // <const> + <obj>

        // Plus Equal Operator Overloads
        void operator += (const Roman &r1);                 // <obj> += <obj>
        void operator += (int v);                           // <obj> += <const>

        // Operator Increment Overload
        Roman operator ++();                                // ++<obj>

};

Roman operator + (const int v, Roman &r1);

// Testing Function Prototypes
void testConstructor();
void testOperatorPlus();
void testOperatorPlusEqual();
void testOperatorIncrement();
//void testConsoleIO();

bool checkTest(string testName, int whatItShouldBe, const Roman& obj);
bool checkTest(string testName, string whatItShouldBe, string whatItIs);

void testOutput();
#endif