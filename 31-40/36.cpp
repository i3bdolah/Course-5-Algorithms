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

void addingOperation(int arr[100], int& arrLength, int goalNum) {
    arrLength++;
    arr[arrLength-1] = goalNum;
}

void inputUserNumInArr(int arr[100], int& arrLength) {
    bool Addmore = true;

    do
    {
        addingOperation(arr, arrLength, readPositiveNums("\nPlease Enter Number : "));
        cout << "\nDo you want to continue ? [Yes = 1] [No = 0] : ";
        cin >> Addmore;
    } while (Addmore);
    
}

void printArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    int arr[100], arrLength = 0;
    inputUserNumInArr(arr, arrLength);

    cout << "\nArray Length: " << arrLength;
    cout << "\nArray Elements: ";
    printArray(arr, arrLength);

    return 0;
}