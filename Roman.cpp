//
// Created by GRees on 10/26/2017.
//

#include "Roman.h"

void checkTest(string a,int b, Roman c){
    cout<<"Roman Number "<<c.getRoman()<<endl;
    cout<<"Decimal Value: "<<c.getValue()<<endl;
   /* if(c.convertFromRoman()==b)
    {
        cout<<"Passed "<<a<<endl;
    }
    else{
        cout<<"Failed "<<a<<endl;
    }*/
}
void testConstructor()
{
    //Test to make sure empty objects are set to zero.
    Roman blank;
    blank.convertFromRoman();
    checkTest("testConstructor #1",0,blank);

    //Test reading in a number.
    Roman a("LXVI");
    a.convertFromRoman();
    checkTest("testConstructor #2",66,a);

    //Test a Bigger Number
    Roman b("MMMDDCCLLXXVVII");
    b.convertFromRoman();
    checkTest("testConstructor #3",4332,b);
}
//Testing + Operator
void testOperatorPlus()
{
    Roman a("XVI");
    a.convertFromRoman();
    Roman b("MDCLXVI");
    b.convertFromRoman();
    Roman c = a + b;
    checkTest("testOperatorPlus #1", 1682, c);
    //Make sure left and right operands weren't modified
    checkTest("testOperatorPlus #2", 16, a);
    checkTest("testOperatorPlus #2", 1666, b);

    //Test adding an object with an int
    c=a+52;
    checkTest("testOperatorPlus #4", 68, c);
    //make sure the left operand wasn't modified
    checkTest("testOperatorPlus #5", 16, a);
    //Test adding an int with an object
    c = 578 + a;

}
