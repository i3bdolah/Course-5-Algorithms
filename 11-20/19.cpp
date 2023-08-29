#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from; 
}

int main() {
    srand((unsigned)time(NULL));

    cout << generateRandomNumber(1,20) << endl;
    cout << generateRandomNumber(1,20) << endl;
    cout << generateRandomNumber(1,20) << endl;
    return 0; 
}