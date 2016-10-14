// Insert your header information here
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations
// Yingqing Huang
// yh3ra
// 10/08

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
    stk = stack<TreeNode*>();
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
    while (stk.size() != 0) {
        stk.pop();
    }
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
    if(ptr -> left != NULL) {
        cleanTree(ptr -> left);
        cleanTree(ptr -> right);
    }
    else if(ptr -> right != NULL) {
        cleanTree(ptr -> right);
        cleanTree(ptr -> left);
    }
    else {
        delete ptr;
    }
}

//Gets data from user
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
            || response[0]=='-' || response[0]=='+' ) {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {
    TreeNode* newNode = new TreeNode(val);
    if(val == "+" || val == "-" || val == "*" || val == "/") {
        newNode -> left = stk.top();
        stk.pop();
        newNode -> right = stk.top();
        stk.pop();
        stk.push(newNode);
    }
    else {
        stk.push(newNode);
    }
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
    if(ptr != NULL) {
        cout << ptr -> value << " ";
        if(ptr -> left != NULL) {
            printPrefix(ptr -> left);
        }
        if(ptr -> right != NULL) {
            printPrefix(ptr -> right);
        }
    }
    else {
        cout << ptr -> value;
    }
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
    if(ptr != NULL) {
        if(ptr -> left != NULL) {
            cout << "(";
            printPrefix(ptr -> left);
        }
        cout << ptr -> value << " ";
        if(ptr -> right != NULL) {
            printPrefix(ptr -> right);
            cout << ")";
        }
    }
    else {
        return;
    }
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
    if(ptr != NULL) {
        if(ptr -> left != NULL) {
            printPrefix(ptr -> left);
        }
        if(ptr -> right != NULL) {
            printPrefix(ptr -> right);
        }
        cout << ptr -> value << " ";
    }
    else {
        return;
    }
}

// Prints tree in all 3 (pre,in,post) forms

void TreeCalc::printOutput() const {
    if (stk.size()!=0 && stk.top()!=NULL) {
        cout << "Expression tree in postfix expression: ";
        // call your implementation of printPostfix()
        printPostfix(stk.top());
        cout << endl;
        
        cout << "Expression tree in infix expression: ";
        // call your implementation of printInfix()
        printInfix(stk.top());
        cout << endl;
        
        cout << "Expression tree in prefix expression: ";
        // call your implementation of printPrefix()
        printPrefix(stk.top());
        cout << endl;
    } else
        cout<< "Size is 0." << endl;
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
    // Traverse the tree and calculates the result
    int total = 0;
    if(ptr -> left == NULL) {
        return atoi((ptr -> value).c_str());
    }
    else if(ptr -> value == "+") {
        total += calculate(ptr -> right) + calculate(ptr -> left);
    }
    else if(ptr -> value == "-") {
        total += calculate(ptr -> right) - calculate(ptr -> left);
    }
    else if(ptr -> value == "*") {
        total += calculate(ptr -> right) * calculate(ptr -> left);
    }
    else if(ptr -> value == "/") {
        total += calculate(ptr -> right) / calculate(ptr -> left);
    }
    return total;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
    int i = 0;
    // call private calculate method here
    while(stk.size() != 0) {
        i += calculate(stk.top());
        stk.pop();
    }
    return i;
}
