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
        Roman(): value(0), romanNumeral("None"){};   //This allows us to make empty objects. (Default Constructor)
        Roman(string romNum): value(),romanNumeral(romNum){};           //This takes Roman numeral as a string.
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
                    case 'M': value = value +1000;
                        break;
                    case 'D': value = value + 500;
                        break;
                    case 'C': value = value + 100;
                        break;
                    default: value += 0;

                }
            }
            return value;
        }
    string getRoman(){          //This returns the string the user inputs for testing purposes
        string a = romanNumeral;
        return a;
    }
    int getValue(){
        return value;
    }
    Roman operator + (Roman const &obj){
        Roman r1;
        r1.value = this->value + obj.value;
        return r1;
    }
    Roman operator + (int x)
    {
        Roman r1(*this);
        r1.value+=x;
        return r1;
    }

};

#endif