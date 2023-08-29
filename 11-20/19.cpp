#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int generateRandomNumber() {
    return rand() % 10 + 1; 
}

int main() {
    int num1 = generateRandomNumber();
    int num2 = generateRandomNumber();
    int num3 = generateRandomNumber();

    cout << num1 << endl;
    cout << num2 << endl;
    cout << num3 << endl;
    return 0; 
}