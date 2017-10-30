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
    public:
        Roman(): value(0){};   //This allows us to make empty objects. (Default Constructor)
        Roman(string romNum): value(0){};           //This takes Roman numeral as a string.
        int convertFromRoman(){

        }
};

#endif