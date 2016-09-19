/*
 * Yingqing Huang
 * yh3ra
 * 09/12
 * testpostfixCal.cpp
 */

#include <iostream>
#include <stack>
#include "postfixCalculator.h"
using namespace std;

int main() {
    postfixCalculator p;
    p.pushNum(1);
    p.pushNum(2);
    p.pushNum(3);
    p.pushNum(4);
    p.pushNum(5);
    p.add();
    cout << "Result for adding is: " << p.getTopValue() << endl;
    p.subtract();
    cout << "Result for subtracting is: " << p.getTopValue() << endl;
    p.multiply();
    cout << "Result for multiplying is: " << p.getTopValue() << endl;
    p.subtract();
    cout << "Result for subtracting is: " << p.getTopValue() << endl;
    p.negate();
    cout << "Result for negating is: " << p.getTopValue() << endl;
    return 0;
};