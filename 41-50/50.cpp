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

float mySqrt(float num) {
    // float subsCount = 0;
    // for (int i = 1; num > 0; i += 2)
    // {
    //     num = num - i;
    //     subsCount++;
    // }
    // return subsCount;

    // Abu-Hadhoud Solution! [Daammmmnnnn Really Simple].
    return pow(num, 0.5);
}


int main() {    
    // float userNumber = readPositiveNums("Please Enter your number : ");
    // float userNumber = 25;
    float userNumber = 50;

    cout << "\nmySqrt() : ";
    cout << mySqrt(userNumber);
    cout << "\nMath sqrt() : ";
    cout << sqrt(userNumber);

    return 0;
}