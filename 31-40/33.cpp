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

void assignKeysToArray(string arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = generateFullKey();
    }
    
} 

void printArray(string arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Array [" << i + 1 << "] : " << arr[i] << "\n";
    }
}

int main() {
    srand((unsigned)time(NULL));

    int NumberOfKeys = readPositiveNums("Enter the keys number : ");
    string arr[100];

    assignKeysToArray(arr, NumberOfKeys);

    cout << "\n";
    printArray(arr, NumberOfKeys);
    return 0;
}