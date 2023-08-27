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

void printInvertedNumPattern(int num) {
    for (int i = num; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << "\n";
    }
    
}

int main() {
    printInvertedNumPattern(readPositiveNums("Enter Your Number : "));
    return 0; 
}