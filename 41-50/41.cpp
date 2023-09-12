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
    arr[arrLength - 1] = goalNum;
}

void reverseArray(int arr[100], int goalArr[100], int arrLength, int& arrGoalLength) {
    for (int i = arrLength - 1; i >= 0; i--)
    {
        addingOperation(goalArr, arrGoalLength, arr[i]);
    }

    cout << "\nArray Being Reversed....\n";
    cout << "Reversing DONE!\n\n";
}

bool isPalindrome(int arr[100], int goalArr[100], int arrLength, int arrGoalLength) {
    if (arrLength != arrGoalLength)
    {
        return false;
    }
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != goalArr[i])
            return false;
    }
    return true;
}

void printPalindrome(int arr[100], int goalArr[100], int arrLength, int arrGoalLength) {
    if (isPalindrome(arr, goalArr, arrLength, arrGoalLength))
    {
        cout << "\nYes, It's a Palidrome Array." << endl;
    }
    else {
        cout << "\nNo, It's NOT a Palidrome Array." << endl;
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
    
    int fArr[100] = {10, 10, 10, 50, 50, 70, 70, 70, 70, 90};
    int lArr[100];
    int arrLength1 = 10;
    int arrLength2 = 0; 


    reverseArray(fArr, lArr, arrLength1, arrLength2);

    cout << "Array 1 = ";
    printArray(fArr, arrLength1);
    cout << "Array 2 = ";
    printArray(lArr, arrLength2);

    printPalindrome(fArr, lArr, arrLength1, arrLength2);
    return 0; 
}