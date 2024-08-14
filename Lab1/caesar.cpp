#include <bits/stdc++.h>
using namespace std;

string caesar(string text, int s, bool encrypt = true) {
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
    int s;
    char choice;

    cout << "Enter Text:" << endl;
    getline(cin, text);

    cout << "Enter Shift:" << endl;
    cin >> s;

    cout << "Encrypt or Decrypt (e/d)?" << endl;
    cin >> choice;

    bool encrypt = (choice == 'e' || choice == 'E');
    string result = caesar(text, s, encrypt);

    cout << "\nResult: " << result << endl;
    return 0;
}
