#include <iostream>
#include <string>
#include <cmath>

using namespace std;


void printFromAAAtoZZZ() {
    string word = "";

    for (int i = 65; i < 91; i++)
    {
        for (int j = 65; j < 91; j++)
        {
            for (int z = 65; z < 91; z++)
            {
                word = word + char(i);
                word = word + char(j);
                word = word + char(z);

                cout << word << "\n";

                word = "";
            }
        }
    }
    
}

int main() {

    printFromAAAtoZZZ();
    return 0; 
}