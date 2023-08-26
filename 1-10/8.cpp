#include <iostream>
#include <string>
#include <string.h>
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

bool comapringTwoNums(char s1, char s2) {
    return s1 == s2;
}

void calcRepeatedDigit(int allDigits, int goalDigit) {
    int remainder = 0;
    int numOfRepeatedGoal = 0;

    while (allDigits > 0)
    {
        remainder = allDigits % 10;
        if (goalDigit == remainder)
        {
            numOfRepeatedGoal++;
        }
        allDigits = allDigits / 10;
    }
    
    cout << "Digit " << goalDigit << " Frequency is " << numOfRepeatedGoal << " Time(s).";
}


int main() {

    int digits = readPositiveNums("Enter Digits : ");
    int goalDigit = readPositiveNums("Enter The Goal Digit : ");

    calcRepeatedDigit(digits,goalDigit);
    

    return 0; 
}