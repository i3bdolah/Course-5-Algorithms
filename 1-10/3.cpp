#include<iostream>
#include<string>
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

bool isPerfect(int num) {
    int sum = 0;

    for (int i = 1; i < num; i++)
    { 
        if (num % i == 0) {
            sum += i;
        }
    }
    return num == sum;
}

void printResult(int num) {
    if (isPerfect(num))
        cout << num << " is Perfect Number" << endl;
    else 
        cout << num << " is NOT Perfect Number" << endl;
}

int main() {
    printResult(readPositiveNums("Enter number : "));
    return 0;
}