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

void fillArrayElements(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = generateRandomNumber(1,20);
    }
}

void copyAndReverseArrayElements(int toArr[100], int fromArr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        toArr[i] = fromArr[(arrLength - 1) - i];
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

    int arrLength = readPositiveNums("Enter Array Length : ");
    int arr[100], arr2[100];

    fillArrayElements(arr, arrLength);


    cout << "\nArray Before Copying and Reverse : ";
    printArray(arr, arrLength);

    copyAndReverseArrayElements(arr2, arr, arrLength);

    cout << "\nArray After Copying and Reverse : ";
    printArray(arr2, arrLength);

    return 0;
}