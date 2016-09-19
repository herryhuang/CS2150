/*
 * Yingqing Huang
 * yh3ra
 * 09/04
 * List.cpp
 */

#include <iostream>
#include <string>
#include "List.h"
#include "ListItr.h"
#include "ListNode.h"
using namespace std;

// Default Constructor
List::List() {
    head = new ListNode;
    tail = new ListNode;
    head->next = tail;
    head->previous = NULL;
    tail->previous = head;
    tail->next = NULL;
    count = 0;
}

// Copy Constructor
List::List(const List& source) {      
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

// Deconstructor
List::~List() {
    makeEmpty();
    delete head;
    delete tail;
}

// Equals Operator
List& List::operator=(const List& source) { 
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

// Returns true if empty; else false
bool List::isEmpty() const {
    return count == 0;
}

// Removes all items except blank head and tail
void List::makeEmpty() {
    while (!isEmpty()) {
        remove(first().retrieve());
    }
}
    
// Returns an iterator that points to the ListNode in the first position
ListItr List::first() {
    return ListItr(head->next);
}

// Returns an iterator that points to the ListNode in the last position
ListItr List::last() {
    return ListItr(tail->previous);
}

// Inserts x after current iterator position p
void List::insertAfter(int x, ListItr position) {
    ListNode *newNode = new ListNode;
    ListNode *pos = position.current;
    ListNode *nextNode = pos -> next;
    
    pos -> next = newNode;
    newNode -> previous = pos;
    nextNode -> previous = newNode;
    newNode -> next = nextNode;    
    newNode -> value = x;
    count++;
}

// Inserts x before current iterator position p
void List::insertBefore(int x, ListItr position) {
    ListNode *newNode = new ListNode;
    ListNode *pos = position.current;
    ListNode *prevNode = pos -> previous;
    
    pos -> previous = newNode;
    newNode -> next = pos;
    prevNode -> next = newNode;
    newNode -> previous = prevNode;
    newNode -> value = x;
    count++;
}

//Insert x at tail of list
void List::insertAtTail(int x) {
    ListNode *newNode = new ListNode;
    ListNode *prevLastNode = tail-> previous;
    prevLastNode -> next = newNode;
    newNode -> previous = prevLastNode;
    newNode -> next = tail;
    tail -> previous = newNode;
    newNode -> value = x;
    count++;
}

// Removes the first occurrence of x
void List::remove(int x) {
    ListItr itr = find(x);
    ListNode *pos = itr.current;
    ListNode *prevNode = pos -> previous;
    ListNode *nextNode = pos -> next;
    prevNode -> next = nextNode;
    nextNode -> previous = prevNode;
    count--;
}

// Returns an iterator that points to the first occurrence of x, else return a iterator to the dummy tail node
ListItr List::find(int x) {
    ListItr itr = first();
    while(!itr.isPastEnd()) {
        if(itr.current->value == x) {
            return itr;
        }
        else {
            itr.moveForward();
        }
    }
    return itr;
}

// Returns the number of elements in the list
int List::size() const {
    return count;
}

// printList: non-member function prototype
void printList(List& source, bool direction) {
//prints list forwards when direction is true
//or backwards when direction is false
    if (direction) {
        ListItr *itr = new ListItr(source.first());
        while (!itr->isPastEnd()) {
            cout << itr->retrieve() << " ";
            itr->moveForward();
        }
    }
    else{
        ListItr *itr = new ListItr(source.last());
        while (!itr->isPastBeginning()) {
            cout << itr->retrieve() << " ";
            itr->moveBackward();
        }
    }
}


