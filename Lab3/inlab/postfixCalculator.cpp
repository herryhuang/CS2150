/*
 * Yingqing Huang
 * yh3ra
 * 09/13
 * postfixCalculator.cpp
 */

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std;

// Constructor
postfixCalculator::postfixCalculator() {
    stk = new stack<int>;
}

// Destructor
postfixCalculator::~postfixCalculator() {
    delete stk;
}

// negates the top element of the stack
void postfixCalculator::negate() {
    int x = stk -> top();
    stk -> pop();
    stk -> push(-x);
}

// adds top two values
void postfixCalculator::add() {
    int x = stk -> top();
    stk -> pop();
    int y = stk -> top();
    stk -> pop();
    stk -> push(y + x);
}

// subtracts top value and the second one
void postfixCalculator::subtract() {
    int x = stk -> top();
    stk -> pop();
    int y = stk -> top();
    stk -> pop();
    stk -> push(y - x);
}

// multiplies top two values
void postfixCalculator::multiply() {
    int x = stk -> top();
    stk -> pop();
    int y = stk -> top();
    stk -> pop();
    stk -> push(y * x);
}

// divides top value and the second one
void postfixCalculator::divide() {
    int x = stk -> top();
    stk -> pop();
    int y = stk -> top();
    stk -> pop();
    stk -> push(y / x);
}

// returns the top value
int postfixCalculator::getTopValue() {
    return stk -> top();
}

// add x to stack
void postfixCalculator::pushNum(int x) {
    stk -> push(x);
}