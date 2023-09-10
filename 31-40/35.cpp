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
        arr[i] = generateRandomNumber(1,100);
    }
}

void searchInArray(int arr[100], int arrLength, int goalNumber) {
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == goalNumber)
        {
            cout << "Yes, The Number Found...\n";
            return;
        }
        
    }
    cout << "No, The Number Not Found...\n";
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
    int arr[100];

    fillArrayElements(arr, arrLength);


    cout << "\nArray : ";
    printArray(arr, arrLength);

    int goalNumber = readPositiveNums("\nEnter Your Goal Number : ");
    searchInArray(arr, arrLength, goalNumber);

    return 0;
}