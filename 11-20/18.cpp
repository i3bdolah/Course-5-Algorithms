#include <iostream>
#include <string>
#include <cmath>

using namespace std;

string readWord(string msg) {
    string word = "";

    cout << msg;
    getline(cin, word);

    return word;
}

string EncryptWord(string word, int encryptionKey) {
    string encryptedWord = "";

    for (int i = 0; i < word.length(); i++)
    {
        encryptedWord = encryptedWord + char(word[i] + encryptionKey);
    }

    return encryptedWord;
}

string DecryptWord(string word, int encryptionKey) {
    string decryptedWord = "";

    for (int i = 0; i < word.length(); i++)
    {
        decryptedWord = decryptedWord + char(word[i] - encryptionKey);
    }

    return decryptedWord;
}

void printEncryptionAndDecryption(string word, int encryptionKey) {
    cout << "Text Before Encryption = " << word << endl;
    cout << "Text After Encryption = " << EncryptWord(word, encryptionKey) << endl;
    cout << "Text After Decryption = " << DecryptWord(EncryptWord(word, encryptionKey), encryptionKey) << endl;
}

int main() {

    const int key = 2;

    printEncryptionAndDecryption(readWord("Enter your word : "), key);
    return 0; 
}