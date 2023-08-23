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

void printReverse(int num) {
    // string numStr = to_string(num);
    // int numStrLength = numStr.length();

    // for (int i = numStrLength; i >= 0; i--)
    // {
    //     cout << numStr[i] << endl;
    // }

    // ___________________________

    // OR ABU-HADHOUD WAY...
    int remainder = 0;

    while (num > 0)
    {
        remainder = num % 10;
        num = num / 10;
        cout << remainder << endl;
    }
    
}

int main() {
    printReverse(readPositiveNums("Enter Number : "));
    return 0; 
}