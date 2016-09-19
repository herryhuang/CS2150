/*
 * Yingqing Huang
 * yh3ra
 * 09/14
 * testpostfixCal.cpp
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include "postfixCalculator.h"
using namespace std;

int main() {
    postfixCalculator p;
    cout << "Type in series of number or operator" << endl;
    cout << "To see the result, type ctrl-D" << endl;
    
    while(cin.good()) {
        string s;
        cin >> s;
        if(s == "") {
            break;
        }
        
        const char *str = s.c_str();
        
        // For positive integers
        if(isdigit(str[0])) {
            int x = atoi(str);
            p.pushNum(x);
        }
        // For positive integers start with "+"
        else if(s[0] == '+' && s.length() > 1) {
            int x = atoi(str);
            p.pushNum(x);
        }
        
        // For negative integers
        else if(s[0] == '-' && s.length() > 1) {
            int x = atoi(str);
            p.pushNum(x);
        }
        
        // For operators
        else if(s == "+") {
            p.add();
        }
        else if(s == "-") {
            p.subtract();
        }
        else if(s == "*") {
            p.multiply();
        }
        else if(s == "/") {
            p.divide();
        }
        else if(s == "~") {
            p.negate();
        }
        // cout << "Value after each step: " << p.getTopValue() << endl;
    }
    cout << "Final value: " << p.getTopValue() << endl;
    return 0;
};