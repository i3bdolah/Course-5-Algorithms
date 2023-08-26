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

void reverseNum(int num) {
    int remainder = 0;
    string totalDigits;
    int reversedNumber = 0;

    // while (num > 0)
    // {
    //     remainder = num % 10;
    //     num = num / 10;
    //     totalDigits+= to_string(remainder);
    //     cout << remainder << endl;
    // }
    // cout << totalDigits << endl;

    // OR ABU-HADHOUD WAY...
    while (num > 0)
    {
        remainder = num % 10; // Takes last num
        num = num / 10; // Removes last num
        reversedNumber = reversedNumber * 10 + remainder; // Adding taken number
    }
    cout << reversedNumber << endl;
}

int main() {

    reverseNum(readPositiveNums("Enter Number : "));
    return 0; 
}