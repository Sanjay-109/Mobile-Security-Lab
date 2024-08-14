#include <bits/stdc++.h>
using namespace std;

const int MATRIX_SIZE = 3;
const int MOD = 26;

int determinant(int matrix[][MATRIX_SIZE], int mod) {
    return (matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
          - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
          + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0])) % mod;
}

int modInverse(int a, int mod) {
    a = a % mod;
    for (int x = 1; x < mod; x++) {
        if ((a * x) % mod == 1)
            return x;
    }
    return 1;
}

void adjugate(int matrix[][MATRIX_SIZE], int adj[][MATRIX_SIZE], int mod) {
    adj[0][0] = (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) % mod;
    adj[0][1] = (matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2]) % mod;
    adj[0][2] = (matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]) % mod;
    adj[1][0] = (matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2]) % mod;
    adj[1][1] = (matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]) % mod;
    adj[1][2] = (matrix[1][0] * matrix[0][2] - matrix[0][0] * matrix[1][2]) % mod;
    adj[2][0] = (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]) % mod;
    adj[2][1] = (matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1]) % mod;
    adj[2][2] = (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) % mod;
}

void inverse(int matrix[][MATRIX_SIZE], int inverseMatrix[][MATRIX_SIZE], int mod) {
    int det = determinant(matrix, mod);
    int detInv = modInverse(det, mod);

    int adj[MATRIX_SIZE][MATRIX_SIZE];
    adjugate(matrix, adj, mod);

    for (int i = 0; i < MATRIX_SIZE; i++)
        for (int j = 0; j < MATRIX_SIZE; j++)
            inverseMatrix[i][j] = (adj[i][j] * detInv + mod) % mod;
}

void getKeyMatrix(string key, int keyMatrix[][MATRIX_SIZE]) {
    int k = 0;
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            keyMatrix[i][j] = islower(key[k]) ? key[k] - 97 : key[k] - 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[][1], int keyMatrix[][MATRIX_SIZE], int messageVector[][1]) {
    int x, i, j;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < 1; j++) {
            cipherMatrix[i][j] = 0;
            for (x = 0; x < MATRIX_SIZE; x++) {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }
            cipherMatrix[i][j] = (cipherMatrix[i][j] % MOD + MOD) % MOD;
        }
    }
}

void decrypt(int messageVector[][1], int inverseKeyMatrix[][MATRIX_SIZE], int cipherMatrix[][1]) {
    int x, i, j;
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < 1; j++) {
            messageVector[i][j] = 0;
            for (x = 0; x < MATRIX_SIZE; x++) {
                messageVector[i][j] += inverseKeyMatrix[i][x] * cipherMatrix[x][j];
            }
            messageVector[i][j] = (messageVector[i][j] % MOD + MOD) % MOD;
        }
    }
}

string HillCipher(string message, string key) {
    int keyMatrix[MATRIX_SIZE][MATRIX_SIZE];
    getKeyMatrix(key, keyMatrix);

    int messageVector[MATRIX_SIZE][1];
    for (int i = 0; i < MATRIX_SIZE; i++)
        messageVector[i][0] = islower(message[i]) ? message[i] - 97 : message[i] - 65;

    int cipherMatrix[MATRIX_SIZE][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);

    string CipherText;
    for (int i = 0; i < MATRIX_SIZE; i++)
        CipherText += cipherMatrix[i][0] + 65;

    return CipherText;
}

string HillDecipher(string cipher, string key) {
    int keyMatrix[MATRIX_SIZE][MATRIX_SIZE];
    getKeyMatrix(key, keyMatrix);

    int inverseKeyMatrix[MATRIX_SIZE][MATRIX_SIZE];
    inverse(keyMatrix, inverseKeyMatrix, MOD);

    int cipherMatrix[MATRIX_SIZE][1];
    for (int i = 0; i < MATRIX_SIZE; i++)
        cipherMatrix[i][0] = islower(cipher[i]) ? cipher[i] - 97 : cipher[i] - 65;

    int messageVector[MATRIX_SIZE][1];
    decrypt(messageVector, inverseKeyMatrix, cipherMatrix);

    string PlainText;
    for (int i = 0; i < MATRIX_SIZE; i++)
        PlainText += messageVector[i][0] + 65;

    return PlainText;
}

int main() {
    string message = "Celest";
    string key = "GYBNQKURP";

    if (message.size() % MATRIX_SIZE != 0) {
        cout << "Message length should be a multiple of " << MATRIX_SIZE << endl;
    } else {
        string result = "";
        for (int i = 0; i < message.size(); i += MATRIX_SIZE) {
            string block = message.substr(i, MATRIX_SIZE);
            string temp = HillCipher(block, key);
            result += temp;
        }
        cout << "Encrypted Message: " << result << endl;

        string decryptedResult = "";
        for (int i = 0; i < result.size(); i += MATRIX_SIZE) {
            string block = result.substr(i, MATRIX_SIZE);
            string temp = HillDecipher(block, key);
            decryptedResult += temp;
        }
        cout << "Decrypted Message: " << decryptedResult << endl;
    }

    return 0;
}
