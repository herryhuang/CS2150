/*
 * Yingqing Huang
 * yh3ra
 * 09/04
 * ListItr.cpp
 */

#include <iostream>
#include <string>
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"
using namespace std;

// Constructor
ListItr::ListItr() {
    current = new ListNode();
}

// One parameter constructor
ListItr::ListItr(ListNode* theNode) {
    current = theNode;
}

// Returns true if past end position
bool ListItr::isPastEnd() const {
    return current->next == NULL;
}

// Returns true if past first position
bool ListItr::isPastBeginning() const {
    return current->previous == NULL;
}

// Advances current to next position in list
void ListItr::moveForward() {
    if (!isPastEnd()) {
        current = current->next;
    }
}

// Moves current back to previous position
void ListItr::moveBackward() {
    if (!isPastBeginning()) {
        current = current->previous;
    }
}

// Returns item in current position
int ListItr::retrieve() const {
    return current->value;
}