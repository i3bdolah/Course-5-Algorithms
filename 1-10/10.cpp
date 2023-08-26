#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int readPositiveNums(string msg) {
    int num = 0;
    do
    {
        cout << msg;
        cin >> num;
    } while (num <= 0);
    return num;
}

int reverseNum(int digits) {
    int remainder = 0;
    int reversedDigits = 0;

    while (digits > 0)
    {
        remainder = digits % 10; // Takes last num
        digits = digits / 10; // Removes last num
        reversedDigits = reversedDigits * 10 + remainder;
    }
    return reversedDigits;
}

void printDigits (int reversedDigits) {
    int remainder = 0;

        while (reversedDigits > 0)
    {
        remainder = reversedDigits % 10; // Takes last num
        reversedDigits = reversedDigits / 10; // Removes last num
        cout << remainder << endl;
    }
}


int main() {

    printDigits(reverseNum(readPositiveNums("Enter Your Digits : ")));

    return 0; 
}