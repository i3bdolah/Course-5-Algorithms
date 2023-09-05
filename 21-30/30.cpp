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

void printArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void sumOfTwoArrays(int arr1[100], int arr2[100], int arrSum[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }
}


int main() {
    srand((unsigned)time(NULL));

    int arr1[100], arr2[100], arrSum[100];
    int arrLength = readPositiveNums("Enter Your Array Length : ");

    assignRandomToArray(arr1, arrLength);
    assignRandomToArray(arr2, arrLength);

    cout << "\nArray 1 Elements: ";
    printArray(arr1, arrLength);

    cout << "\nArray 2 Elements: ";
    printArray(arr2, arrLength);

    sumOfTwoArrays(arr1, arr2, arrSum,arrLength);
    cout << "\nArrays Sum: ";
    printArray(arrSum, arrLength);
    cout << "\n";

    return 0; 
}