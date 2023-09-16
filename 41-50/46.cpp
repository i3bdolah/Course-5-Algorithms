#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int readPositiveNums(string msg) {
    int num = 0;
        cout << msg;
        cin >> num;
    return num;
}

// int myAbs(int num) {
    // int countFromNumtoZero = 0;

    // if (num >= 0)
    // {
    //     return num;
    // }
    
    // while (num != 0)
    // {
    //     num++;
    //     countFromNumtoZero++;
    // }
    
    // return num + countFromNumtoZero;
// }

int myAbs(int num) {
    // Abu-Hadhoud Solution! [Daammmmnnnn Really Simple].
    if (num > 0)
        return num;
    else
        return num * -1;    
}


int main() {    
    int userNumber = readPositiveNums("Please Enter your negative number : ");

    cout << "\nMyAbs : ";
    cout << myAbs(userNumber);
    cout << "\nMath Abs : ";
    cout << abs(userNumber);

    return 0;
}