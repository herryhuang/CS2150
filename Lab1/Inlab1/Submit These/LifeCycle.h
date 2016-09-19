// LifeCycle.h
// Yingqing Huang, yh3ra, 08/30

#ifndef LIFECYCLE_H
#define LIFECYCLE_H

#include <iostream>

class MyObject {
    public:
        static int numObjs;
        MyObject(const char *n = "--default--");      // default constructor
        MyObject(const MyObject& rhs);                // copy constructor
        ~MyObject();                                  // destructor
        std::string getName() const {
            return name;
        }
        void setName(const std::string newName) {
            name = newName;
        }
        friend std::ostream& operator<<(std::ostream& output, const MyObject& obj);
    private:
        std::string name;
        int id;
};


//---------------------------------------------------------- prototypes
MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);
#endif
