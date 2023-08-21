#include <iostream>

using namespace std;

void printHeader() {

    cout << "Multiplications " << endl;
    cout << "\t";

    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n";
}

string columnSeperator(int i) {
    if (i < 10)
    {
        return "   |";
    }
    else {
        return "  |";
    }
}

void printMultiplicationTable() {
    printHeader();
        for (int i = 1; i <= 10; i++) {
        cout << " " << i << columnSeperator(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << j * i << "\t";
        }
        cout << endl;
    }
}

int main() {

    printMultiplicationTable();

    // printHeader();
    // for (int i = 1; i <= 10; i++)
    // {
    //     cout << i << "  | ";
    //     for (int j = 1; j <= 10; j++)
    //     {
    //         cout << j * i << "   ";
    //     }

    //     cout << "\n";
    // }
    
    return 0; 

}