#include<bits/stdc++.h>
using namespace std;

void displayStateArray(string mat[2][2]) {
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
}

string subArray[4][4] = {{"11","00","31","32"}, {"21","01","03","23"}, {"12","13","02","10"}, {"33","22","20","30"}};
string invSubArray[4][4] = {{"01","11","22","12"}, {"23","00","20","21"}, {"32","10","31","13"}, {"33","02","03","30"}};
string mixArray[2][2] = {{"00", "11"},{"22", "10"}};
string roundKey[2][2] = {{"10", "22"}, {"11", "00"}};

void invSubstitute(string ct[2][2]) {
	string x;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			x = ct[i][j];
			ct[i][j] = invSubArray[x[0]-'0'][x[1]-'0'];
		}
	}
}

void invShiftRows(string ct[2][2]) {
	for(int i=0; i<2; i++) {
		int k = i;
		while(k) {
			string temp = ct[i][1];
			for(int j=0; j>=0; j--) {
				ct[i][j+1] = ct[i][j];
			}
			ct[i][0] = temp;
			k--;
		}
	}
}

void invMixColumns(string ct[2][2]) {
	string x, y, z;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			x = ct[i][j];
			y = mixArray[i][j];
			z = "";
			z += ((x[0]-'0') ^ (y[0]-'0')) + '0';
			z += ((x[1]-'0') ^ (y[1]-'0')) + '0';
			ct[i][j] = z;
		}
	}
}

void addRoundKey(string ct[2][2]) {
	string x, y, z;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			x = ct[i][j];
			y = roundKey[i][j];
			z = "";
			z += ((x[0]-'0') ^ (y[0]-'0')) + '0';
			z += ((x[1]-'0') ^ (y[1]-'0')) + '0';
			ct[i][j] = z;
		}
	}
}

int main() {
	string ct[2][2];		
	cout << "Enter ciphertext : ";
	
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			cin >> ct[i][j];
		}
	}
	
	cout << "Ciphertext : \n";
	displayStateArray(ct);
	
	addRoundKey(ct);
	cout << "After adding round key : \n";
	displayStateArray(ct);
	cout << "\n\n";
	
	invShiftRows(ct);
	cout << "After shifting rows : \n";
	displayStateArray(ct);
	invSubstitute(ct);
	cout << "After substitution : \n";
	displayStateArray(ct);
	addRoundKey(ct);
	cout << "After adding round key : \n";
	displayStateArray(ct);
	invMixColumns(ct);
	cout << "After mixing coloumns : \n";
	displayStateArray(ct);
	
	cout << "\n\n";
	
	invShiftRows(ct);
	cout << "After shifting rows : \n";
	displayStateArray(ct);
	invSubstitute(ct);
	cout << "After substitution : \n";
	displayStateArray(ct);
	addRoundKey(ct);
	cout << "After adding round key : \n";
	displayStateArray(ct);
	cout << "\n\n";
	
	cout << "Plain Text : ";
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			cout << ct[i][j] << " ";
		}
	}
	cout << "\n";	
}
