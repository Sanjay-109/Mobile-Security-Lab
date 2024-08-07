#include <bits/stdc++.h>
using namespace std;

string caesar(string text, int s) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        
        if (isupper(text[i]))
            result += char(int(text[i] + s - 65) % 26 + 65);
        
        else if (isspace(text[i]))
            result += text[i];
        else
            result += char(int(text[i] + s - 97) % 26 + 97);
    }

    return result;
}

int main() {
    string text;
    int s;
    cout << "Enter Text" << endl;
    getline(cin, text);
    cout << "Enter Shift" << endl;
    cin >> s;
    cout << "\nCipher: " << caesar(text, s);
    return 0;
}
