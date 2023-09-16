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

float myFloor(float num) {
    if (num > 0)
    {
        return int(num);
    }
    else {
        return int(num) - 1;
    }
}


int main() {    
    float userNumber = readPositiveNums("Please Enter your negative number : ");
    // float userNumber = -10.7;
    // float userNumber = 10.2;

    cout << "\nmyFloor() : ";
    cout << myFloor(userNumber);
    cout << "\nMath floor() : ";
    cout << floor(userNumber);

    return 0;
}