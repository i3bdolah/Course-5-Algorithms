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

void assignRandomToArray(int arr[100], int arrLength1) {
    for (int i = 0; i < arrLength1; i++)
    {
        arr[i] = generateRandomNumber(1, 100);
    }
}

bool isPrimeNumer(int num) {
    int halfNum = num / 2;

    for (int i = 2; i < halfNum; i++)
    {
        if (num % 2 == 0)
        {
            return false;
        }
    }
        return true;
}

void copiyngPrimeInArray(int arr1[100], int arr2[100], int arrLength1, int& arrLength2) {
    for (int i = 0; i < arrLength1; i++)
    {
        if (isPrimeNumer(arr1[i]))
        {
            arr2[arrLength2] = arr1[i];
            arrLength2++;
        }
    }
}

void printArray(int arr[100], int arrLength1) {
    for (int i = 0; i < arrLength1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main() {
    srand((unsigned)time(NULL));
    
    int arr1[100];
    int arrLength1 = readPositiveNums("Enter Your Array Length : ");
    assignRandomToArray(arr1, arrLength1);

    int arr2[100];
    int arrLength2 = 0;
    copiyngPrimeInArray(arr1, arr2, arrLength1, arrLength2);

    cout << "\n(Array 1) Elements: ";
    printArray(arr1, arrLength1);

    cout << "\n(Array 2) Elements: ";
    printArray(arr2, arrLength2);
    return 0; 
}