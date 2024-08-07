#include<bits/stdc++.h>
using namespace std;

const int a = 17;
const int b = 20;

string encryptMessage(string msg) {
	string cipher = ""; 
	for (int i = 0; i < msg.length(); i++) {
		
		if(msg[i]!=' ') 
			cipher = cipher + (char) ((((a * (islower(msg[i]) ? msg[i] - 'a' : msg[i] - 'A') ) + b) % 26) + 'A');
		else
			cipher += msg[i];	 
	}
	return cipher;
}


int main(void) {
	string msg = "Hello World";
	
	string cipherText = encryptMessage(msg);
	cout << "Encrypted Message is : " << cipherText<<endl;

	return 0;
}
