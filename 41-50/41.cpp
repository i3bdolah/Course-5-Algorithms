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

bool isPalindrome(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[(arrLength - 1) - i])
            return false;
    }
    return true;    
}

void printPalindrome(int arr[100], int arrLength) {
    if (isPalindrome(arr, arrLength))
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
    
    int arr[100] = {1,2,3,3,2,1};
    int arrLength = 6;



    printPalindrome(arr, arrLength);

    cout << "\nArray = ";
    printArray(arr, arrLength);

    return 0; 
}