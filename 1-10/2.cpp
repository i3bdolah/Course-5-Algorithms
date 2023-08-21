#include<iostream>
#include<string>

using namespace std;

enum enPrimeNOTPrime {Prime = 1, NotPrime = 2};

int readPositiveNums(string msg) {
    int num = 0;
    do
    {
        cout << msg;
        cin >> num;
    } while (num <= 0);
    return num;
}

enPrimeNOTPrime checkPrimeNumer(int num) {
    int halfNum = num / 2;

    for (int i = 2; i < halfNum; i++)
    {
        if (num % 2 == 0)
        {
            return enPrimeNOTPrime::NotPrime;
        }
    }
        return enPrimeNOTPrime::Prime;
    
}

void primeFrom1toN(int num) {
    for (int i = 1; i <= num; i++)
    {
        if (checkPrimeNumer(i) == enPrimeNOTPrime::Prime)
        {
            cout << i << endl;
        }
    }
    
}

int main() {
    // for (int i = 2; i <= 100; i++)
    // {
    primeFrom1toN(readPositiveNums("Enter Positive Number : "));
    // }
    
    
    return 0; 

}