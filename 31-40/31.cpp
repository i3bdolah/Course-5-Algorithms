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
        arr[i] = i + 1;
    }
}

void shuffleArrayElements(int arr[100], int arrLength) {
    int num1, num2;
    int temp = 0;
    
    for (int i = 0; i < arrLength; i++)
    {
        num1 = generateRandomNumber(0,arrLength-1);
        num2 = generateRandomNumber(0,arrLength-1);
        
        temp = arr[num1];
        arr[num1] = arr[num2];
        arr[num2] = temp;
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
    int arr[100], shuffledArr[100];

    fillArrayElements(arr, arrLength);

    cout << "\nArray Before Shuffle : ";
    printArray(arr, arrLength);

    shuffleArrayElements(arr, arrLength);

    cout << "\nArray Aftr Shuffle : ";
    printArray(arr, arrLength);

    return 0;
}