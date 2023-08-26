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

int calcFrequncyDigit(int allDigits, int goalDigit) {
    int remainder = 0;
    int numOfFrequncy = 0;

    while (allDigits > 0)
    {
        remainder = allDigits % 10;
        allDigits = allDigits / 10;

        if (goalDigit == remainder)
        {
            numOfFrequncy++;
        }
    }
    
    return numOfFrequncy;
}


int main() {

    int digits = readPositiveNums("Enter Digits : ");
    int goalDigit = readPositiveNums("Enter The Goal Digit : ");


    cout << "Digit " << goalDigit << " Frequency is " << calcFrequncyDigit(digits,goalDigit) << " Time(s)." << endl;
    

    return 0; 
}