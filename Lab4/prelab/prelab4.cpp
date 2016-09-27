/*
 * Yingqing Huang
 * yh3ra
 * 09/18
 * prelab4.cpp
 */

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void sizeOfTest() {
    // Size of types
    cout << "Size of int: " << sizeof(int) << endl;
    cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
    cout << "Size of float: " << sizeof(float) << endl;
    cout << "Size of double: " << sizeof(double) << endl;
    cout << "Size of char: " << sizeof(char) << endl;
    cout << "Size of bool: " << sizeof(bool) << endl;
    
    // Size of pointers
    cout << "Size of int*: " << sizeof(int*) << endl;
    cout << "Size of char*: " << sizeof(char*) << endl;
    cout << "Size of double*: " << sizeof(double*) << endl;
    
}

void outputBinary(unsigned int x) {
    string binaryNum = "0";
    for (int i = 31; i >= 0; i--) {
        if (x && (1 << x)) {
            binaryNum += "1";
        }
        else {
            binaryNum += "0";
        }
    }
    cout << "The binary number for " << x << " is " << binaryNum << endl;
}

void overflow() {
    unsigned int max = 4294967295;
    max++;
    cout << "Overflow: " << max << endl;
    cout << "The reason it happens is because for 32-bit number, 1 is already in each place. By adding 1, there is no place to put it, which cause an overflow" << endl;
}

// Main method
int main() {
    int x;
    cout << "Value of x: ";
    cin >> x;
    
    sizeOfTest();
    outputBinary(x);
    overflow();
}