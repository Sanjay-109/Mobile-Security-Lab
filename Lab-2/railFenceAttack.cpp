#include <iostream>
#include <string>
#include <vector>

using namespace std;

string decryptRailFenceCipher(const string& cipherText, int numRails) {
    if (numRails == 1) return cipherText;

    int n = cipherText.length();
    vector<vector<char>> rail(numRails, vector<char>(n, '\n'));
    
    bool dirDown = false;
    int row = 0, col = 0;

    for (int i = 0; i < n; i++) {
        if (row == 0 || row == numRails - 1)
            dirDown = !dirDown;
        rail[row][col++] = '*';
        dirDown ? row++ : row--;
    }

    int index = 0;
    for (int i = 0; i < numRails; i++) {
        for (int j = 0; j < n; j++) {
            if (rail[i][j] == '*' && index < n) {
                rail[i][j] = cipherText[index++];
            }
        }
    }

    string result;
    row = 0, col = 0;
    dirDown = false;
    for (int i = 0; i < n; i++) {
        if (row == 0 || row == numRails - 1)
            dirDown = !dirDown;
        result.push_back(rail[row][col++]);
        dirDown ? row++ : row--;
    }

    return result;
}

void attackRailFenceCipher(const string& cipherText) {
    int n = cipherText.length();
    for (int numRails = 2; numRails <= n/2; numRails++) {
        string decryptedText = decryptRailFenceCipher(cipherText, numRails);
        cout << "Rails: " << numRails << ", Decrypted Text: " << decryptedText << endl;
    }
}

int main() {
    string cipherText;
    cout << "Enter Ciphertext to attack: ";
    getline(cin, cipherText);
    attackRailFenceCipher(cipherText);
    return 0;
}
