/*
 * Yingqing Huang
 * yh3ra
 * inlab4.cpp
 * 09/20
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
    // Part 1
    bool boo = false;
    char ch = '0';
    int num = 0;
    double d = 0.0;
    int* intP = NULL;
    
    cout << "boolean is " << boo << endl;
    cout << "character is " << ch << endl;
    cout << "integer is " << num << endl;
    cout << "double is " << d << endl;
    cout << "integer pointer is " << intP << endl;
    
    
    // Arrays (part 2)
    int IntArray[10];
    char CharArray[10];
    int IntArray2D[6][5];
    char CharArray2D[6][5];
    
    // Assign value to IntArray
    for (int i = 0; i < 10; i++) {
        IntArray[i] = i;
    }
    
    // Assign value to CharArray
    for (int i = 0; i < 10; i++) {
        CharArray[i] = ch; // Use ch from previous part
        ch++;
    }
    
    // Assign value to IntArray2D
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; i++) {
            IntArray2D[i][j] = i * j;    // Breakpoint
        }
    }
    
    // Assign value to CharArray2D
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; i++) {
            CharArray2D[i][j] = ch;
            ch++;
        }
    }
};