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

void addingOperation(int arr[100], int& arrLength, int goalNum) {
    arrLength++;
    arr[arrLength - 1] = goalNum;
}

void copyOddNumbers(int fArr[100], int lArr[100], int fArrLength, int& lArrLength) {
    for (int i = 0; i < fArrLength; i++)
    {
        // if (fArr[i] % 2 == 0)
        if (fArr[i] % 2 != 0)
        {
            addingOperation(lArr, lArrLength, fArr[i]);
        }
        
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
    
    int fArr[100], lArr[100];
    int arrLength1 = readPositiveNums("Enter Your Array Length : ");
    int arrLength2 = 0;

    assignRandomToArray(fArr, arrLength1);
    copyOddNumbers(fArr, lArr, arrLength1, arrLength2);

    cout << "\n(Array 1) Elements: ";
    printArray(fArr, arrLength1);

    cout << "\n(Array 2) Elements: ";
    printArray(lArr, arrLength2);
    return 0; 
}