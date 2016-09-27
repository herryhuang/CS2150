/*
 * Yingqing Huang
 * yh3ra
 * 09/21
 * bitCounter.cpp
 */

#include <iostream>
#include <cstdlib>
using namespace std;


int counter(int x) {
    if (x == 1) {
        return 1;
    }
    
    else if (x % 2 == 0) {
        return counter(x / 2);
    }
    
    else {
        return counter((x - 1) / 2) + 1;
    }
}


int main (int argc, char **argv) {
    int num = atoi(argv[1]);
    cout << "Number of bit: " << counter(num) << endl;
}
    