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

float myCeil(float num) {
    if (num > 0)
    {
        return int(num) + 1;
    }
    else {
        return int(num) ;
    }
}


int main() {    
    float userNumber = readPositiveNums("Please Enter your negative number : ");
    // float userNumber = -10.7;
    // float userNumber = 10.2;

    cout << "\nmyCeil() : ";
    cout << myCeil(userNumber);
    cout << "\nMath ceil() : ";
    cout << ceil(userNumber);

    return 0;
}