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

int printSumArrElement(int arr[100], int arrLength) {
    int sum = 0;

    for (int i = 0; i < arrLength; i++)
    {
            sum += arr[i];
    }
    return sum;
}

float printAvgArrElement(int arr[100], int arrLength) {
    return (float) printSumArrElement(arr, arrLength) / arrLength;
}


int main() {
    srand((unsigned)time(NULL));

    int arr[100];
    int arrLength = readPositiveNums("Enter Your Array Length : ");

    assignRandomToArray(arr, arrLength);

    cout << "\nArray Elements: ";
    printArray(arr, arrLength);

    cout << "\nAvg Number is: ";
    cout << printAvgArrElement(arr, arrLength) << endl;

    return 0; 
}