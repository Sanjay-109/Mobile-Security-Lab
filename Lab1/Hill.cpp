#include <bits/stdc++.h>
using namespace std;

void getKeyMatrix(string key, int keyMatrix[][3]) {
	int k = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			keyMatrix[i][j] = islower(key[k]) ? key[k] % 97 : key[k] % 65;
			k++;
		}
	}
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][3], int messageVector[][1]) {
	int x, i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 1; j++) {
			cipherMatrix[i][j] = 0;
		
			for (x = 0; x < 3; x++) {
				cipherMatrix[i][j] += 
					keyMatrix[i][x] * messageVector[x][j];
			}
		
			cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		}
	}
}

string HillCipher(string message, string key) {
	int keyMatrix[3][3];
	getKeyMatrix(key, keyMatrix);

	int messageVector[3][1];

	for (int i = 0; i < 3; i++)
		messageVector[i][0] = islower(message[i]) ? message[i] % 97 : message[i] % 65;

	int cipherMatrix[3][1];
	encrypt(cipherMatrix, keyMatrix, messageVector);

	string CipherText;

	for (int i = 0; i < 3; i++)
        if (islower(message[i])) {
            CipherText += cipherMatrix[i][0] + 97;
        } else {
            CipherText += cipherMatrix[i][0] + 65;
        }
		
    
    return CipherText;
}

int main()
{
	string message = "ABcdEf";

	string key = "abcdefghi";
    
    int i = 0;
    if ( message.size() % 3 != 0) {
        cout << "Message length should be multiple of 3" << endl;
    } else {
        string result = "";
        for ( int i = 0; i < message.size(); i = i + 3 ) {
            string block = message.substr(i, 3);
            string temp = HillCipher(block, key);
            result += temp;
        }
        cout << result << endl;
    }
    
	

	return 0;
}
