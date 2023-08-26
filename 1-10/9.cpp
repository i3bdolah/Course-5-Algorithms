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

void calcGoalDigits(int allDigits) {

    for (int i = 0; i < 10; i++)
    {
        short digitFrequency = 0;
        digitFrequency = calcFrequncyDigit(allDigits, i);

        if (digitFrequency > 0)
        {
            cout << "Digit " << i << " Frequency is " << calcFrequncyDigit(allDigits, i) << " Time(s)." << endl;
        }
    }
        
}


int main() {

    calcGoalDigits(readPositiveNums("Enter Digits : "));

    return 0; 
}