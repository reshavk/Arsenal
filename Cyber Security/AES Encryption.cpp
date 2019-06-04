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

void substitute(string pt[2][2]) {
	string x;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			x = pt[i][j];
			pt[i][j] = subArray[x[0]-'0'][x[1]-'0'];
		}
	}
}

void shiftRows(string pt[2][2]) {
	for(int i=0; i<2; i++) {
		int k = i;
		while(k) {
			string temp = pt[i][0];
			for(int j=1; j<2; j++) {
				pt[i][j-1] = pt[i][j];
			}
			pt[i][1] = temp;
			k--;
		}
	}
}

void mixColumns(string pt[2][2]) {
	string x, y, z;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			x = pt[i][j];
			y = mixArray[i][j];
			z = "";
			z += ((x[0]-'0') ^ (y[0]-'0')) + '0';
			z += ((x[1]-'0') ^ (y[1]-'0')) + '0';
			pt[i][j] = z;
		}
	}
}

void addRoundKey(string pt[2][2]) {
	string x, y, z;
	int c1, c2;
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			x = pt[i][j];
			y = roundKey[i][j];
			z = "";
			z += ((x[0]-'0') ^ (y[0]-'0')) + '0';
			z += ((x[1]-'0') ^ (y[1]-'0')) + '0';
			pt[i][j] = z;
		}
	}
}

int main() {
	string pt[2][2];		
	cout << "Enter plaintext : ";
	
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			cin >> pt[i][j];
		}
	}
	
	cout << "Plaintext : \n";
	displayStateArray(pt);
	
	addRoundKey(pt);
	cout << "After adding round key : \n";
	displayStateArray(pt);
	cout << "\n\n";
	
	substitute(pt);
	cout << "After substitution : \n";
	displayStateArray(pt);
	shiftRows(pt);
	cout << "After shifting rows : \n";
	displayStateArray(pt);
	mixColumns(pt);
	cout << "After mixing coloumns : \n";
	displayStateArray(pt);
	addRoundKey(pt);
	cout << "After adding round key : \n";
	displayStateArray(pt);
	cout << "\n\n";
	
	substitute(pt);
	cout << "After substitution : \n";
	displayStateArray(pt);
	shiftRows(pt);
	cout << "After shifting rows : \n";
	displayStateArray(pt);
	addRoundKey(pt);
	cout << "After adding round key : \n";
	displayStateArray(pt);
	cout << "\n\n";
	
	cout << "Cipher Text : ";
	for(int i=0; i<2; i++) {
		for(int j=0; j<2; j++) {
			cout << pt[i][j] << " ";
		}
	}
	cout << "\n";	
}
