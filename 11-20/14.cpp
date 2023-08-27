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

void printInvertedLetterPattern(int num) {
    for (int i = num + 64; i > 64; i--)
    {
         for (int j = 1; j <= i - 64; j++)
        {
            cout << char(i);
        }
        cout << "\n";
    }
    
}

int main() {
    printInvertedLetterPattern(readPositiveNums("Enter Your Number : "));
    return 0; 
}