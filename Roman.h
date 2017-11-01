//
// Created by GRees on 10/26/2017.
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
        string romanNumeral;
    public:
        Roman();                            //This allows us to make empty objects. (Default Constructor)
        Roman(const string&);               //This takes Roman numeral as a string.
        Roman(int romNum): value(romNum),romanNumeral(""){};

        void convertFromRoman(const string&);             //Converts Roman numeral to a decimal number

        string convertToRoman() const;      //The method that helps us take an integer and turn it into a roman numeral

        string getRoman();                  //This returns the string the user inputs for testing purposes

        unsigned int getValue() const;

        friend bool checkTest(string testName, int whatItShouldBe, const Roman& obj);

        friend void testOutput();

        Roman operator + (const Roman &r1) const;

        Roman operator + (int x);

        //Plus Equal Operators
        Roman& operator += (Roman const &obj);

        //add on an integer
        Roman& operator += (int x);

        //Operator Increment
        Roman& operator ++();

};

// Testing Function Prototypes
void testConstructor();
void testOperatorPlus();
void testOperatorPlusEqual();
void testOperatorIncrement();
void testConsoleIO();

bool checkTest(string testName, int whatItShouldBe, const Roman& obj);

void testOutput();
#endif