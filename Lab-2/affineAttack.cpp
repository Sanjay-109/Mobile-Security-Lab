#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int charToNum(char c) {
    return toupper(c) - 'A';
}

char numToChar(int n) {
    return 'A' + n;
}

int multiplicativeInverse(int a, int m) {
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1;
}

bool isMeaningful(const string& text) {
    return text.find("HELLO") != string::npos;
}

string decryptAffineCipher(const string& cipherText, int a, int b, int m) {
    string decryptedText = "";
    int invA = multiplicativeInverse(a, m);
    
    if (invA == -1) {
        return "";
    }
    
    for (char c : cipherText) {
        if (isalpha(c)) {
            int y = charToNum(c);
            int x = (invA * (y - b + m)) % m; 
            decryptedText += numToChar(x);
        } else {
            decryptedText += c; 
        }
    }
    
    return decryptedText;
}

void attackAffineCipher(const string& cipherText) {
    int m = 26;
    int possibleAs[] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25}; 
    
    for (int a : possibleAs) {
        for (int b = 0; b < m; b++) {
            string decryptedText = decryptAffineCipher(cipherText, a, b, m);
            
            if (!decryptedText.empty()) {
                cout << "Decrypted Text: " << decryptedText << endl;
                cout << "Key (a, b): (" << a << ", " << b << ")" << endl;
            }
        }
    }
}

int main() {
    
    string cipherText;

    cout << "Enter Ciphertext to attack : ";

    getline(cin, cipherText);
    
    attackAffineCipher(cipherText);
    
    return 0;
}
