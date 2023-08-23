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

void sumOfAllDigits(int num) {
    int remainder = 0;

    while (num > 0)
    {
        remainder = remainder + (num % 10);
        num = num / 10;
        cout << remainder << endl;
    }
    cout << "Total = " << remainder << endl;
}


int main() {
    sumOfAllDigits(readPositiveNums("Enter Number : "));
    return 0; 
}