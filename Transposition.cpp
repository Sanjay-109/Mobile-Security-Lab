#include <bits/stdc++.h>
using namespace std;

string Rail(string text, int key) {
	char rail[key][(text.length())];

	for (int i=0; i < key; i++)
		for (int j = 0; j < text.length(); j++)
			rail[i][j] = '\n';

	bool dir = false;
	int row = 0, col = 0;

	for (int i=0; i < text.length(); i++) {
		if (row == 0 || row == key-1)
			dir = !dir;
		rail[row][col++] = text[i];
		dir ? row++ : row--;
	}

	string result;
	for (int i=0; i < key; i++)
		for (int j=0; j < text.length(); j++)
			if (rail[i][j]!='\n')
				result.push_back(rail[i][j]);

	return result;
}

int main() {
	cout << Rail("Hello World", 3) << endl;

	return 0;
}
