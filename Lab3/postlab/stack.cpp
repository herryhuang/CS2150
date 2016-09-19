/*
 * Yingqing Huang
 * yh3ra
 * 09/14
 * stack.cpp
 */

#include <iostream>
#include "stack.h"
using namespace std;

// Constructor
stack::stack() {
    newStack = new List;
    count = 0;
}

stack::~stack() {
    newStack -> makeEmpty();
    delete newStack;
}

void stack::push(int x) {
    newStack -> insertAtTail(x);
}

int stack::top() {
    return newStack -> last().retrieve();
}

void stack::pop() {
    ListItr *itr = new ListItr((newStack -> last()));
    newStack -> remove(itr -> retrieve());
}

bool stack::empty() {
    return count == 0;
}
