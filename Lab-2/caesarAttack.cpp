#include <bits/stdc++.h>
using namespace std;

string caesarAttack(string text, int s, bool encrypt = true) {
    string result = "";
    s = encrypt ? s : -s;  

    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + s - 65) % 26 + 65);
        } else if (islower(text[i])) {
            result += char(int(text[i] + s - 97) % 26 + 97);
        } else {
            result += text[i];  
        }
    }

    return result;
}

int main() {
    string text;

    cout << "Enter Ciphertext to attack:";

    getline(cin, text);
    
    for (int i = 0; i < 26; i++) {
        string result;
        result = caesarAttack(text, i, true);
        cout << result << endl;
    }
    return 0;
}
