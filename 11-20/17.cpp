#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string readWord(string msg) {
    string word = "";

    cout << msg;
    cin >> word;

    return word;
}

void printFromAAAtoZZZ(string enteredWord) {
    string word = "";
    int trial = 0;

    for (int i = 65; i < 91; i++)
    {
        for (int j = 65; j < 91; j++)
        {
            for (int z = 65; z < 91; z++)
            {
                trial++;
                word = word + char(i);
                word = word + char(j);
                word = word + char(z);
                cout << "Trial [" << trial << "] : " << word << "\n";

                if (word == enteredWord)
                {
                    cout << "\n";
                    cout << "Password is " << enteredWord << endl;
                    cout << "Found after " << trial << " Trial(s) " << endl;
                    return;
                }
                else {
                    word = "";
                }
                
            }
        }
    }
    
}

int main() {

    printFromAAAtoZZZ(readWord("Enter your Letters : "));
    return 0; 
}