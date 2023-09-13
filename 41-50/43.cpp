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

void countEvenNumbersinArray(int arr[100], int arrLength) {
    int evenCounts = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] % 2 == 0)
            evenCounts++;
    }
    cout << "\nEven numbers count is: " << evenCounts;     
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
    countEvenNumbersinArray(arr, arrLength);
    return 0; 
}