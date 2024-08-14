#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

void toLowerCase(string &plain) {
    for (char &c : plain) {
        if (isupper(c))
            c = tolower(c);
    }
}

int removeSpaces(string &plain) {
    plain.erase(remove(plain.begin(), plain.end(), ' '), plain.end());
    return plain.length();
}

void generateKeyTable(const string &key, char keyT[SIZE][SIZE]) {
    bool dicty[26] = {false};
    int i = 0, j = 0;

    for (char c : key) {
        if (c != 'j' && !dicty[c - 'a']) {
            dicty[c - 'a'] = true;
            keyT[i][j++] = c;
            if (j == SIZE) {
                j = 0;
                i++;
            }
        }
    }

    for (int k = 0; k < 26; k++) {
        if (!dicty[k] && k != 'j' - 'a') {
            keyT[i][j++] = static_cast<char>(k + 'a');
            if (j == SIZE) {
                j = 0;
                i++;
            }
        }
    }
}

void search(const char keyT[SIZE][SIZE], char a, char b, int arr[]) {
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

int mod5(int a) {
    return a % SIZE;
}

int prepare(string &str) {
    if (str.length() % 2 != 0) {
        str += 'z';
    }
    return str.length();
}

void encrypt(string &str, const char keyT[SIZE][SIZE]) {
    int a[4];
    for (size_t i = 0; i < str.length(); i += 2) {
        search(keyT, str[i], str[i + 1], a);

        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][mod5(a[1] + 1)];
            str[i + 1] = keyT[a[0]][mod5(a[3] + 1)];
        } else if (a[1] == a[3]) {
            str[i] = keyT[mod5(a[0] + 1)][a[1]];
            str[i + 1] = keyT[mod5(a[2] + 1)][a[1]];
        } else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

void encryptByPlayfairCipher(string &str, const string &key) {
    char keyT[SIZE][SIZE];
    string keyLower = key;
    string strLower = str;

    toLowerCase(keyLower);
    toLowerCase(strLower);
    removeSpaces(keyLower);
    removeSpaces(strLower);

    int ps = prepare(strLower);
    generateKeyTable(keyLower, keyT);
    encrypt(strLower, keyT);
    
    str = strLower;
}

int main() {
    string str, key;

    cout << "Enter Text" << endl;
    getline(cin, str);

    cout << "Enter Key" << endl;
    getline(cin, key);

    encryptByPlayfairCipher(str, key);

    cout << "Cipher text: " << str << "\n";

    return 0;
}
