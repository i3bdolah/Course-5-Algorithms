#include<iostream>
#include<string>
#include <cmath>

using namespace std;

enum enPerfect { NotPerfect = 0, Perfect = 1 };

int readPositiveNums(string msg) {
    int num = 0;
    do
    {
        cout << msg;
        cin >> num;
    } while (num <= 0);
    return num;
}

enPerfect calcPerfect(int num) {
    int sumAllDivisors = 0;
    int initailNum = 0;

    for (int i = 1; i < num; i++)
    {
        if (num % i == 0) {
            sumAllDivisors = sumAllDivisors + i;
            cout << sumAllDivisors << endl;
        }
    }
    
    

    if (sumAllDivisors == num)
        return enPerfect::Perfect;
    else 
        return enPerfect::NotPerfect;
    
}

void printPerfectResult(enPerfect enperfect) {
    if (enperfect == enPerfect::Perfect)
        cout << "PERFECT" << endl;
    else
        cout << "NOT PERFECT" << endl;    
}

int main() {
    
    printPerfectResult(calcPerfect(readPositiveNums("Enter your number : ")));
    return 0;
}