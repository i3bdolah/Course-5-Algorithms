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

int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from; 
}

string generateCapitalLetters(int num) {
    string word = "";
    for (int i = 1; i <= num; i++)
    {
        word = word + char(generateRandomNumber(65,90));
    }
    return word;
}

string generateFullKey() { // Generating Key with correct formating
    return generateCapitalLetters(4) + "-" + generateCapitalLetters(4) + "-" + generateCapitalLetters(4) + "-" + generateCapitalLetters(4);
}

void printKeys(int num) {
    for (int i = 1; i <= num; i++)
    {
        cout << "Key [" << i << "] : ";
        cout << generateFullKey() << endl; 
    }
    
}

int main() {
    srand((unsigned)time(NULL));


    printKeys(readPositiveNums("Enter your number : "));
    return 0; 
}