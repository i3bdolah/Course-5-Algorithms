#include <iostream>

using namespace std;

int main() {

    // int nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "     1   2   3   4   5   6   7   8   9   10" << endl;
    cout << "_____________________________________________" << endl;
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "  | ";
        for (int j = 1; j <= 10; j++)
        {
            cout << j * i << "   ";
        }

        cout << "\n";
    }
    
    return 0; 

}