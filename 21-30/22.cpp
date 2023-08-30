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

int readIndexValue(string msg, int i, string msg2) {
    int num = 0;
    do
    {
        cout << msg << i << msg2;
        cin >> num;
    } while (num <= 0);
    return num;
}

// void printArray(int arr) {
//     for (int i = 0; i < arr.length; i++)
//     {
//         cout << "Original Array : " << arr[i] << endl;
//     }
// }

void createArray(int arrayLength) {
    int userArray[arrayLength];
    int goalNum = 0;
    int occurancesFound = 0;

    for (int i = 0; i < arrayLength; i++)
    {
        userArray[i] = readIndexValue("Enter Element [",i + 1,"] : ");
    }

    goalNum = readPositiveNums("Enter Goal Number : ");

    // printArray(userArray);
    cout << "\n";
    cout << "Original Array : ";
    for (int i = 0; i < arrayLength; i++)
    {
        cout << userArray[i] << " ";
    }
    cout << "\n";

    for (int i = 0; i < arrayLength; i++)
    {
        if (goalNum == userArray[i])
        {
            occurancesFound++;
        }   
    }

    cout << goalNum << " is repeated " << occurancesFound << " time(s)" << endl;
}

int main() {

    createArray(readPositiveNums("Enter Array Length : "));

    return 0;
    
}