#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void addingOperation(int arr[100], int& arrLength, int goalNum) {
    arrLength++;
    arr[arrLength - 1] = goalNum;
}

short findNumPositionInArray(int arr[100], int arrLength, int goalNum) {
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == goalNum)
            return i;
    }
    return -1;    
}

bool checkIsDitinct(int arr[100], int arrLength, int goalNum) {
    return findNumPositionInArray(arr, arrLength, goalNum) == -1;
}

void copyDistinctNumbers(int fArr[100], int lArr[100], int fArrLength, int& lArrLength) {
    for (int i = 0; i < fArrLength; i++)
    {
        if (checkIsDitinct(lArr, lArrLength, fArr[i]))
            addingOperation(lArr, lArrLength, fArr[i]);
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
    
    int fArr[100] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};
    int lArr[100];
    int arrLength1 = 10;
    int arrLength2 = 0;

    copyDistinctNumbers(fArr, lArr, arrLength1, arrLength2);

    cout << "\n(Array 1) Elements: ";
    printArray(fArr, arrLength1);
    cout << "\n(Array 2) Elements: ";
    printArray(lArr, arrLength2);
    return 0; 
}