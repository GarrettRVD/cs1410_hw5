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
        Roman(): value(0){};   //This allows us to make empty objects. (Default Constructor)
        Roman(string romNum): value(0),romanNumeral(romNum){};           //This takes Roman numeral as a string.
        int convertFromRoman(){
            int length = romanNumeral.length();
            for (int i = 0; i < length; ++i) {
                switch(romanNumeral.at(i)){
                    case 'I' : value = value + 1;
                        break;
                    case 'X': value = value + 10;
                        break;
                    case 'L': value = value + 50;
                        break;
                    case 'V': value = value + 5;
                        break;
                    default: value += 0;
                }
            }
            return value;
        }
        void printRoman(){
            cout<<value;
        }
};

#endif