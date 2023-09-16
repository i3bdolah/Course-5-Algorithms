#include <iostream>
#include <string>
#include <cmath>

using namespace std;

float readPositiveNums(string msg) {
    float num = 0;
        cout << msg;
        cin >> num;
    return num;
}

int myAbs(int num) {
    // Abu-Hadhoud Solution! [Daammmmnnnn Really Simple].
    if (num > 0)
        return num;
    else
        return num * -1;    
}

float getFraction(float num) {
    return num - (int) num;
}

float myRound(float num) {
    float fractionPart = getFraction(num);
    float intPart = num - fractionPart;

    if (myAbs(fractionPart) >= .5) 
        if (num > 0)
            return intPart + 1;
        else
            return intPart - 1;

    else 
        return intPart;
}


int main() {    
    float userNumber = readPositiveNums("Please Enter your negative number : ");
    // float userNumber = -10.7;
    // float userNumber = 10.2;

    cout << "\nmyRound() : ";
    cout << myRound(userNumber);
    cout << "\nMath round() : ";
    cout << round(userNumber);

    return 0;
}