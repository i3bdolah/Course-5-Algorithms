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

void readArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
}

void printArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int checkGoalNum(int arr[100], int arrLength, int goalNum) {
    int numOfOccurances = 0;

    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == goalNum)
        {
            numOfOccurances += 1; // or numOfOccurances++;
        }
    }
    return numOfOccurances;
}


int main() {
    int arr[100];
    int arrLength = readPositiveNums("Enter Your Array Length : ");
    int goalNum;

    cout << "\nEnter your Array Elements : \n";
    readArray(arr, arrLength);
    cout << "\n";

    goalNum = readPositiveNums("Enter your Goal Number : ");
    cout << "\n";

    cout << "Original Array : ";
    printArray(arr, arrLength);
    cout << "\n";

    cout << "Number " << goalNum << " is repeated ";
    cout << checkGoalNum(arr,arrLength,goalNum) << " time(s)";

    return 0;
    
}