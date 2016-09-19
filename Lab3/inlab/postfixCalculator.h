/*
 * Yingqing Huang
 * yh3ra
 * 09/13
 * postfixCalculator.h
 */

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
#include <stack>
using namespace std;

class postfixCalculator {
    public:
        postfixCalculator();       // Constructor
        ~postfixCalculator();      // Destructor
        void negate();             // negates the top element of the stack
        void add();                // adds top two values
        void subtract();           // subtracts top value and the second one
        void multiply();           // multiplies top two values
        void divide();             // divides top value and the second one
        int getTopValue();            // returns the top value
        void pushNum(int x);        //add x to stack
    private:
        stack<int> *stk;
};
#endif