#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int generateRandomNumber(int from, int to) {
    return rand() % (to - from + 1) + from; 
}

void randomizeCharacters() {
    cout << "Small Letter = " << char(generateRandomNumber(97,122)) << endl;
    cout << "Capital Letter = " << char(generateRandomNumber(65,90)) << endl;
    cout << "Special Character = " << char(generateRandomNumber(33,47)) << endl;
    cout << "Digit = " << char(generateRandomNumber(48,57)) << endl;
}

int main() {
    srand((unsigned)time(NULL));
    // for (int i = 0; i < 140; i++)
    // {
    // cout << i << " = " <<  char(i) << endl;
    // }
    
    randomizeCharacters();
    

    return 0; 
}