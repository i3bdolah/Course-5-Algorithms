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
        arr[i] = generateRandomNumber(-100,100);
    }
}

void countNegativeNumbersinArray(int arr[100], int arrLength) {
    int count = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < 0)
            count++;
    }
    cout << "\nNegative numbers count is: " << count;     
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

    int arrLength = readPositiveNums("\nEnter Array Length : ");
    int arr[100];

    fillArrayElements(arr, arrLength);


    printArray(arr, arrLength);
    countNegativeNumbersinArray(arr, arrLength);
    return 0; 
}