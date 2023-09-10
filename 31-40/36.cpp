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

void addingOperation(int arr[100], int arrLength, int goalNum) {
    arrLength++;
    arr[arrLength-1] = goalNum;
}

void printArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arrLength = 0;
    int arr[100];
    bool activeOp = true;

    while (activeOp)
    {
        int arrNum = readPositiveNums("\nPlease Enter Number : ");
        addingOperation(arr,arrLength,arrNum);

        int ifContinue = readPositiveNums("Do you want to continue ? [Yes = 1] [No = 0] : ");
        if (ifContinue == 1)
        {
            continue;
        }
        else {
            activeOp = false;
            break;
        }
    }
    
    cout << "\nArray Length: " << arrLength;
    cout << "\nArray Elements: ";
    printArray(arr, arrLength);

    return 0;
}