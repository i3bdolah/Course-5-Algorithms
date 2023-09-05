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

void assignRandomToArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = generateRandomNumber(1, 100);
    }
}

void copiyngArray(int fArr[100], int lArr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        lArr[i] = fArr[i];
    }
}

void printArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));
    
    int fArr[100];
    int lArr[100];
    int arrLength = readPositiveNums("Enter Your Array Length : ");

    assignRandomToArray(fArr, arrLength);
    copiyngArray(fArr, lArr, arrLength);

    cout << "\n(Array 1) Elements: ";
    printArray(fArr, arrLength);

    cout << "\n(Array 2) Elements: ";
    printArray(lArr, arrLength);
    return 0; 
}