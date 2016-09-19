/*
 * Yingqing Huang
 * yh3ra
 * 09/14
 * stack.h
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

class stack {
public:
    stack();              // Constructor
    ~stack();             // Destructor
    void push(int x);     // push x to the top of the stack
    int top();            // return the top value
    void pop();           // remove top value from stack
    bool empty();         // return true if the stack is empty
    
private:
    List *newStack;
    int count;
};

#endif