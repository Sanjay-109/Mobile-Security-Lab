#include <bits/stdc++.h>
using namespace std;

string Rail(string text, int key) {
    char rail[key][(text.length())];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';

    bool dir = false;
    int row = 0, col = 0;

    for (int i = 0; i < text.length(); i++) {
        if (row == 0 || row == key - 1)
            dir = !dir;
        rail[row][col++] = text[i];
        dir ? row++ : row--;
    }

    string result;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            if (rail[i][j] != '\n')
                result.push_back(rail[i][j]);

    return result;
}

string RailDecrypt(string cipher, int key) {
    char rail[key][cipher.length()];
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            rail[i][j] = '\n';

    bool dir = false;
    int row = 0, col = 0;

    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0 || row == key - 1)
            dir = !dir;
        rail[row][col++] = '*';
        dir ? row++ : row--;
    }

    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < cipher.length(); j++)
            if (rail[i][j] == '*' && index < cipher.length())
                rail[i][j] = cipher[index++];

    string result;
    row = 0, col = 0;
    dir = false;
    for (int i = 0; i < cipher.length(); i++) {
        if (row == 0 || row == key - 1)
            dir = !dir;
        if (rail[row][col] != '\n')
            result.push_back(rail[row][col++]);
        dir ? row++ : row--;
    }

    return result;
}

int main() {
    string text = "attack at once";
    int key = 2;

    string cipherText = Rail(text, key);
    cout << "Encrypted Message is : " << cipherText << endl;

    string decryptedText = RailDecrypt(cipherText, key);
    cout << "Decrypted Message is : " << decryptedText << endl;

    return 0;
}
