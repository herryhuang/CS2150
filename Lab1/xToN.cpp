#include <iostream>
using namespace std;                                                                    

int xton(int a , int b) {
    if (b == 1) {
        return a;                                                                               
    }
    else {
        return a * xton(a, b - 1);                                                                 
    }
}

int main() {
    int x, y;                                                                            
    cin >> x;                                                                               
    cin >> y;                                                                               
    cout << xton(x, y) << endl;                                            
    return 0;                                                                               
}