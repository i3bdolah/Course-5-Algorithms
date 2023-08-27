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

// int countDigit(int num) {
//    int count = 0;
//    while(num != 0) {
//       num = num / 10;
//       count++;
//    }
//    return count;
// }

// bool isOdd(int num) {
//     int remainder = num % 2;
//     if (remainder > 0) {
//         return true;
//     }
//     else {
//         return false;
//     }
// }

int reverseNum(int digits) {
    int remainder = 0;
    int reversedDigits = 0;

    while (digits > 0)
    {
        remainder = digits % 10; // Takes last num
        digits = digits / 10; // Removes last num
        reversedDigits = reversedDigits * 10 + remainder;
    }
    return reversedDigits;
}

// bool isPalindrome(int num) {
//     int remainder1 = 0;
//     int remainder2 = 0;
//     int digitsLength = countDigit(num);
//     int reversedDigits = reverseNum(num);
//     if (isOdd(digitsLength))
//     {
//         // for (int i = 1; i <= digitsLength / 2; i++)
//         // {
//         //     remainder1 = num % 10;
//         //     remainder2 = reversedDigits % 10;
//         //     num = num / 10;
//         //     reversedDigits = reversedDigits / 10;
//         //     if (remainder1 != remainder2)
//         //     {
//         //         return false;
//         //     }
//         // }
//         if (reversedDigits - num == 0)
//         {
//             return true;
//         }
//         return false;
//     }
//     else {
//         return false;
//     }
// }

bool isPalindrome(int num) {
    return num == reverseNum(num);
}


void printPalindrome(int num) {
    if (isPalindrome(num))
    {
        cout << "Yes, It's a Palidrome number." << endl;
    }
    else {
        cout << "No, It's NOT a Palidrome number." << endl;
    }
    
}

int main() {
    printPalindrome(readPositiveNums("Enter Your Digits : "));
    return 0; 
}