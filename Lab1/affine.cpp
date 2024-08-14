#include <bits/stdc++.h>
using namespace std;

const int a = 17;
const int b = 20;
const int MOD = 26;

int modInverse(int a, int mod) {
    a = a % mod;
    for (int x = 1; x < mod; x++) {
        if ((a * x) % mod == 1)
            return x;
    }
    return 1;
}

string encryptMessage(string msg) {
    string cipher = ""; 
    for (int i = 0; i < msg.length(); i++) {
        if (isalpha(msg[i])) {
            char base = islower(msg[i]) ? 'a' : 'A';
            cipher += char((a * (msg[i] - base) + b) % MOD + base);
        } else {
            cipher += msg[i];
        }
    }
    return cipher;
}

string decryptMessage(string cipher) {
    string message = "";
    int a_inv = modInverse(a, MOD); 

    for (int i = 0; i < cipher.length(); i++) {
        if (isalpha(cipher[i])) {
            char base = islower(cipher[i]) ? 'a' : 'A';
            message += char((a_inv * ((cipher[i] - base - b + MOD) % MOD)) % MOD + base);
        } else {
            message += cipher[i]; 
        }
    }
    return message;
}

int main(void) {
    string msg = "Hello World";
    
    string cipherText = encryptMessage(msg);
    cout << "Encrypted Message is : " << cipherText << endl;

    string decryptedText = decryptMessage(cipherText);
    cout << "Decrypted Message is : " << decryptedText << endl;

    return 0;
}
